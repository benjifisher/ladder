<?php
/**
 * @file
 * ladder_lessons.default_lessons.inc
 */

/**
 * Implements hook_default_lessons().
 */
function ladder_lessons_default_lessons() {
  $export = array();

  $lessons = new stdClass;
  $lessons->disabled = FALSE; /* Edit this to true to make a default lessons disabled initially */
  $lessons->api_version = 1;
  $lessons->name = 'ladder_create_a_ladder';
  $lessons->title = 'Create/Edit a learning ladder or leadership ladder (Ladder module)';
  $lessons->author = '';
  $lessons->project = 'ladder';
  $lessons->project_type = 'contrib';
  $lessons->lesson_type = 'configuration';
  $lessons->description = '';
  $lessons->version = '';
  $lessons->steps = 'TODO write this';
  $lessons->permission = '';
  $export['ladder_create_a_ladder'] = $lessons;

  return $export;
}
