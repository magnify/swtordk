<?php
/**
 * @file
 * swtor_external_news_import.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function swtor_external_news_import_taxonomy_default_vocabularies() {
  return array(
    'news_category' => array(
      'name' => 'News category',
      'machine_name' => 'news_category',
      'description' => 'External news category',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
