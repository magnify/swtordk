advanced_from
-------------
diff --git a/modules/contrib/advanced_forum/includes/core-overrides.inc b/modules/contrib/advanced_forum/includes/core-overrides.inc
index fd6586d..dac6efb 100644
--- a/modules/contrib/advanced_forum/includes/core-overrides.inc
+++ b/modules/contrib/advanced_forum/includes/core-overrides.inc
@@ -172,8 +172,8 @@ function advanced_forum_forum_load($tid = NULL) {
     $query->addExpression('CASE ncs.last_comment_uid WHEN 0 THEN ncs.last_comment_name ELSE u2.name END', 'last_comment_name');
 
     $topics = $query
-      ->fields('ncs', array('last_comment_timestamp', 'last_comment_uid'))
-      ->fields('n', array('nid', 'title', 'type'))
+      ->fields('ncs', array('last_comment_timestamp', 'last_comment_uid', 'comment_count'))
+      ->fields('n', array('nid', 'title', 'type', 'changed'))
       ->condition('n.status', 1)
       ->orderBy('last_comment_timestamp', 'DESC')
       ->range(0, $post_count)
@@ -195,6 +195,9 @@ function advanced_forum_forum_load($tid = NULL) {
         $forum->last_post[] = $last_post;
       }
       else {
+        if ($topic->comment_count == 0) {
+          $last_post->created = $topic->changed;
+        }
         $forum->last_post = $last_post;
       }
     }

