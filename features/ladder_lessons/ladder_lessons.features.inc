<?php
/**
 * @file
 * ladder_lessons.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ladder_lessons_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "lessons" && $api == "default_lessons") {
    return array("version" => "1");
  }
}
