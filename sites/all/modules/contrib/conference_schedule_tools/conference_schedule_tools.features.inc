<?php
/**
 * @file
 * conference_schedule_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function conference_schedule_tools_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function conference_schedule_tools_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function conference_schedule_tools_node_info() {
  $items = array(
    'featured_session' => array(
      'name' => t('Featured Session'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'room' => array(
      'name' => t('Room'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'time_slot' => array(
      'name' => t('Time Slot'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
