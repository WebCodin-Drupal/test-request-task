<?php

/**
 * @file
 * Views support.
 */

/**
 * Implements hook_views_data().
 */
function request_core_views_data() {
  $data['node']['time_request'] = array(
    'title' => t('Spent time for solve request'),
    'help' => t('How long it took to solve request.'),
    'field' => array(
      'handler' => 'request_core_handler_custom_solve_request',
    ),
  );

  return $data;
}
