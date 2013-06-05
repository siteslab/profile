<?php
/**
 * @file
 * rideshare.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rideshare_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rideshare_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rideshare_node_info() {
  $items = array(
    'rideshare' => array(
      'name' => t('Rideshare'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Type of Request: Have a Ride / Need a Ride'),
      'help' => t('Indicate whether you have a ride or need a ride at the top of the posting.'),
    ),
  );
  return $items;
}
