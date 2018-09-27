<?php

/**
 * @file
 * Custom handler.
 */

/**
 * Field handler to display request time.
 *
 * @ingroup views_field_handlers
 */
class request_core_handler_custom_solve_request extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['field_request_time_start'] = array(
      'table' => 'field_data_field_request_time',
      'field' => 'field_request_time_value',
    );
    $this->additional_fields['field_request_time_end'] = array(
      'table' => 'field_data_field_request_time',
      'field' => 'field_request_time_value2',
    );
  }

  public function query() {
    $this->add_additional_fields();
  }

  /**
   * Render the field.
   *
   * @param array $values
   *   The values retrieved from the database.
   */
  public function render($values) {
    $request_open = $this->get_value($values, 'field_request_time_start');
    $request_close = $this->get_value($values, 'field_request_time_end');
    if (!empty($request_open) && !empty($request_close) && $request_open != $request_close) {
      $close_time_unix = new DateTime();
      $close_time_unix->setTimestamp($request_close);
      $open_time_unix = new DateTime();
      $open_time_unix->setTimestamp($request_open);
      $spent_time = $close_time_unix->diff($open_time_unix, TRUE);
      $hours = $spent_time->h + ($spent_time->days * 24);

      // Store average time.
      request_core_views_average_time($hours);

      return array(
        '#type' => 'container',
        '#attributes' => array(
          'style' => array('color:' . ((int)$hours >= 24 ? 'red' : 'green')),
        ),
        'value' => array(
          '#markup' => $hours . 'h:' . $spent_time->i . 'min',
        ),
      );
    }

    return '';
  }
}


