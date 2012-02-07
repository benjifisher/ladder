<?php
/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'ladder_rung',  // As defined in hook_schema(), mymodule_myobj.
  'access' => 'administer ladder',  // Define a permission users must have to access these pages.

  // Define the menu item.
  'menu' => array(
    'menu item' => 'ladder',
    'menu title' => t('Ladder'),
    'menu description' => t('Administer ladder.'),
  ),

  // Define user interface texts.
  'title singular' => t('rung'),
  'title plural' => t('rungs'),
  'title singular proper' => t('Rung'),
  'title plural proper' => t('Rungs'),
  // Define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'ladder_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
  ),
  // Use this to modify the default export UI interface.
  'handler' => array(
    'class' => 'ladder_export_ui',
    'parent' => 'ctools_export_ui',
  ),
);

/**
* Define the preset add/edit form.
*/
function ladder_ctools_export_ui_form(&$form, &$form_state) {
  $rung = $form_state['item'];

  // rung's configuration interface.
  // Ctools includes name field automatically on its own.
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Human readable rung title.'),
    '#default_value' => $rung->title,
    '#required' => true,
    '#maxlength' => 255,
  );
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('Explain what someone will be able to do after completing this rung.'),
    '#default_value' => $rung->description,
    '#maxlength' => 255,
  );
  // @todo Add validation for this field.
  $form['ladder'] = array(
    '#type' => 'textfield',
    '#title' => t('Ladder name'),
    '#description' => t('Comma separated list of ladders where this rung will appear. Ladders are specified in the path to the ladder like this: www.example.com/ladder/ladder-name.'),
    '#default_value' => $rung->ladder,
    '#required' => true,
    '#maxlength' => 255,
  );
  $form['lesson'] = array(
    '#type' => 'select',
    '#title' => t('Related lesson'),
    '#description' => t('This rung of the ladder will link to the selected lesson. (!administer. !create)', 
      array('!administer' => l(t('Administer lessons'), 'admin/structure/lessons'), '!create' => l(t('Add a new lesson.'), 'admin/structure/lessons/add'))),
    '#default_value' => $rung->lesson,
    '#options' => lessons_get_lessons(TRUE),
    '#required' => true,
    '#maxlength' => 255,
  );
  $form['css_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS Class'),
    '#description' => t('CSS class or classes to be wrapped around rung.'), // TODO Add some defaults to ladder.css and offer as options here.
    '#default_value' => $rung->css_class,
    '#maxlength' => 255,
  );
  $form['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Weight'),
    '#description' => t('Determine sort order of this rungs relative to other rungs in the ladder.'),
    '#default_value' => $rung->weight,
    '#maxlength' => 4,
  );

}
