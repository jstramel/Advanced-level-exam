<?php
/**
* @file
* Result of call to module administration pages for
* Forcontu Exam 7
*/

/**
 * Function handler for forcontu_exam7_admin_settings()
 */

function forcontu_exam7_admin_settings() {
  /**
  * With node_type_get_types() we obtain information about all content
  * types, each one in the form of an object, so that one only has to
  * select the name of the content type in order to show it in the options.
  */

  $content_types_list = node_type_get_types();
  foreach ($content_types_list as $key => $type) {
    $list[$key] = $type->name;
  }
  $form['forcontu_exam7_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select the type where the module will act'),
    '#options' => $list,
    // the variable used to store the configuration;
    // it is best practice to name it the same as the form field
    // used, in this case 'node_expiration_date_node_types'.
    '#default_value' => variable_get('forcontu_exam7_node_types', array('article')),
    '#description' => t('The selected content types will allow for content review.'),
  );

  return system_settings_form($form);
}
