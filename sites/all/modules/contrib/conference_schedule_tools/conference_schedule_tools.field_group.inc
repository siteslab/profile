<?php
/**
 * @file
 * conference_schedule_tools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function conference_schedule_tools_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_presenters|node|session|form';
  $field_group->group_name = 'group_presenters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'session';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Presenters',
    'weight' => '5',
    'children' => array(
      0 => 'field_presenter_one',
      1 => 'field_presenter_two',
      2 => 'field_presenter_three',
      3 => 'field_presetner_four',
      4 => 'field_presenter_five',
      5 => 'field_presetner_six',
      6 => 'field_presenter_seven',
      7 => 'field_presenter_eight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Presenters',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_presenters|node|session|form'] = $field_group;

  return $export;
}
