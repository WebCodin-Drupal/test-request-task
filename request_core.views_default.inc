<?php

/**
 * @file
 * Views request view default.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function request_core_views_default_views_alter(&$views) {
  $view = new view();
  $view->name = 'request_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Request list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Request list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_request_status' => 'field_request_status',
    'field_customer_email' => 'field_customer_email',
    'field_customer_name' => 'field_customer_name',
    'field_request_open_time' => 'field_request_open_time',
    'field_request_close_time' => 'field_request_close_time',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request_open_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request_close_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_request_customer_target_id']['id'] = 'field_request_customer_target_id';
  $handler->display->display_options['relationships']['field_request_customer_target_id']['table'] = 'field_data_field_request_customer';
  $handler->display->display_options['relationships']['field_request_customer_target_id']['field'] = 'field_request_customer_target_id';
  $handler->display->display_options['relationships']['field_request_customer_target_id']['required'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::request_core_request_status_change' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Request title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Request status */
  $handler->display->display_options['fields']['field_request_status']['id'] = 'field_request_status';
  $handler->display->display_options['fields']['field_request_status']['table'] = 'field_data_field_request_status';
  $handler->display->display_options['fields']['field_request_status']['field'] = 'field_request_status';
  $handler->display->display_options['fields']['field_request_status']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Customer email */
  $handler->display->display_options['fields']['field_customer_email']['id'] = 'field_customer_email';
  $handler->display->display_options['fields']['field_customer_email']['table'] = 'field_data_field_customer_email';
  $handler->display->display_options['fields']['field_customer_email']['field'] = 'field_customer_email';
  $handler->display->display_options['fields']['field_customer_email']['relationship'] = 'field_request_customer_target_id';
  $handler->display->display_options['fields']['field_customer_email']['type'] = 'email_plain';
  /* Field: Content: Customer full name */
  $handler->display->display_options['fields']['field_customer_name']['id'] = 'field_customer_name';
  $handler->display->display_options['fields']['field_customer_name']['table'] = 'field_data_field_customer_name';
  $handler->display->display_options['fields']['field_customer_name']['field'] = 'field_customer_name';
  $handler->display->display_options['fields']['field_customer_name']['relationship'] = 'field_request_customer_target_id';
  /* Field: Content: Request time */
  $handler->display->display_options['fields']['field_request_time']['id'] = 'field_request_time';
  $handler->display->display_options['fields']['field_request_time']['table'] = 'field_data_field_request_time';
  $handler->display->display_options['fields']['field_request_time']['field'] = 'field_request_time';
  $handler->display->display_options['fields']['field_request_time']['label'] = 'Request open time';
  $handler->display->display_options['fields']['field_request_time']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'F j, Y, g:i a',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Request time */
  $handler->display->display_options['fields']['field_request_time_1']['id'] = 'field_request_time_1';
  $handler->display->display_options['fields']['field_request_time_1']['table'] = 'field_data_field_request_time';
  $handler->display->display_options['fields']['field_request_time_1']['field'] = 'field_request_time';
  $handler->display->display_options['fields']['field_request_time_1']['label'] = 'Request close time';
  $handler->display->display_options['fields']['field_request_time_1']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'F j, Y, g:i a',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Spent time for solve request */
  $handler->display->display_options['fields']['time_request']['id'] = 'time_request';
  $handler->display->display_options['fields']['time_request']['table'] = 'node';
  $handler->display->display_options['fields']['time_request']['field'] = 'time_request';
  $handler->display->display_options['fields']['time_request']['empty'] = '-';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'request' => 'request',
  );

  /* Display: Request list */
  $handler = $view->new_display('page', 'Request list', 'request_list_page');
  $handler->display->display_options['path'] = 'admin/request-list';

  $export['request_list'] = $view;

  return $export;
}
