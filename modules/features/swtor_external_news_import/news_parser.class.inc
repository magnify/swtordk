<?php

class NewsParser extends FeedsParser {

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {

    feeds_include_library('common_syndication_parser.inc', 'common_syndication_parser');
    
    // Parser data
    $items = array();
    $xml = new SimpleXMLElement($fetcher_result->getRaw());
    
    // Build result object.
    $result = new FeedsParserResult();
    $result->title = (string)$xml->title;
    $result->description = 'Star Wars: The Old Republic news';
    $result->link = (string)$xml->id;

    // Run through news items
    foreach ($xml->entry as $entry) {
      $item = array();
      $item['id'] = (string)$entry->id;
      $item['title'] = (string)$entry->title;
      $item['updated'] = _parser_common_syndication_parse_date((string)$entry->updated);
      $item['author'] = (string)$entry->author->name;
      $item['summary'] = (string)$entry->summary;
      $item['url'] = (string)$entry->id;

      foreach ($entry->link as $link) {
        if (strstr($link['type'], 'image')) {
          $item['image'] = (string)$link['href'];
        }
      }
      
      // Add feed item
      $result->items[] = $item;
    }
    
    return $result;
  }

  public function getMappingSources() {
    return array(
      'id' => array(
        'name' => t('GUID'),
        'description' => t('GUID for the news item.'),
      ),
      'title' => array(
        'name' => t('Title'),
        'description' => t('News title.'),
      ),
      'updated' => array(
        'name' => t('Post date'),
        'description' => t('The date where the news was updated.'),
      ),
      'author' => array(
        'name' => t('Author'),
        'description' => t('The news article author.'),
      ),
      'summary' => array(
        'name' => t('Summary'),
        'description' => t('A summary of the news (teaser).'),
      ),
      'image' => array(
        'name' => t('Image URL'),
        'description' => t('URL to the news title image.'),
      ),
      'url' => array(
        'name' => t('URL'),
        'description' => t('URL back to the source.'),
      ),
    ) + parent::getMappingSources();
  }
}