<?php
/**
 * @file
 * conference_video.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function conference_video_field_default_fields() {
  $fields = array();

  // Exported field: 'node-conference_video-field_image'.
  $fields['node-conference_video-field_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_image',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'conference_video',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'A Thumbnail for the video',
      'required' => 1,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '34',
      ),
    ),
  );

  // Exported field: 'node-conference_video-field_the_url_youtube_or_vimeo_'.
  $fields['node-conference_video-field_the_url_youtube_or_vimeo_'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_the_url_youtube_or_vimeo_',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'video_embed_field',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'video_embed_field',
    ),
    'field_instance' => array(
      'bundle' => 'conference_video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'video_embed_field',
          'settings' => array(
            'description' => 1,
            'description_position' => 'bottom',
            'video_style' => 'normal',
          ),
          'type' => 'video_embed_field',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_the_url_youtube_or_vimeo_',
      'label' => 'The URL (YouTube or Vimeo)',
      'required' => 1,
      'settings' => array(
        'description_field' => 0,
        'description_length' => 128,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'video_embed_field',
        'settings' => array(),
        'type' => 'video_embed_field_video',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-conference_video-field_video_transcript'.
  $fields['node-conference_video-field_video_transcript'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_video_transcript',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'conference_video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Add a transcript of the video. This is a required field to ensure the widest possible access to the video. If you do not yet have a transcript for the video, enter the name of the person who has agreed to transcribe the video.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_video_transcript',
      'label' => 'Video Transcript',
      'required' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '7',
        ),
        'type' => 'text_textarea',
        'weight' => '35',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A Thumbnail for the video');
  t('Add a transcript of the video. This is a required field to ensure the widest possible access to the video. If you do not yet have a transcript for the video, enter the name of the person who has agreed to transcribe the video.');
  t('The URL (YouTube or Vimeo)');
  t('Video Transcript');

  return $fields;
}
