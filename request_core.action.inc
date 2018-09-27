<?php

/**
 * @file
 * Provides an action for manage client requests.
 */

define('REQUEST_CORE_STATUS_FIELD', 'field_request_status');

/**
 * Implements hook_action_info().
 */
function request_core_action_info() {
  return array(
    'request_core_request_status_change' => array(
      'type' => 'node',
      'label' => t('Change request status'),
      'configurable' => FALSE,
      'triggers' => array('any'),
      'behavior' => array('changes_property'),
      'vbo_configurable' => TRUE,
      'pass rows' => TRUE,
    ),
  );
}

/**
 * Callback function for request status change.
 */
function request_core_request_status_change($entity, $context = array()) {
  global $user;

  $field_language = field_language($context['entity_type'], $entity, REQUEST_CORE_STATUS_FIELD);
  $entity->{REQUEST_CORE_STATUS_FIELD}[$field_language][0]['tid'] = $context['status'];

  watchdog('node', '%user change request "%title" status to %status.', array(
    '%user' => $user->name,
    '%status' => $context['status'],
    '%title' => $entity->title,
  ));
}

/**
 * Callback function for vbo configuration form.
 */
function request_core_request_status_change_form($context, &$form_state) {
  $form = array();

  $options = [];
  $settings = $context['settings'];
  if ($status_terms = taxonomy_vocabulary_machine_name_load(REQUEST_CORE_STATUS_TAX_NAME)) {
    if ($terms_tree = taxonomy_get_tree($status_terms->vid)) {
      foreach ($terms_tree as $term) {
        $options[$term->tid] = $term->name;
      }
    }
  }

  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Choose status'),
    '#options' => $options,
    '#default_value' => isset($settings['status']) ? $settings['status'] : '',
  );

  return $form;
}

/**
 * Callback function for vbo configuration form submit.
 */
function request_core_request_status_change_submit($form, $form_state) {
  $return = array();
  $return['status'] = $form_state['values']['status'];
  return $return;
}
