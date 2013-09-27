<?php

/**
 * @file
 * Page callbacks for the Reviewer Views module.
 */

/*
 * Page callback for personal pending reviews from profile page
 */
function reviewer_views_personal_view($user) {
  $query = new EntityFieldQuery();
  // fieldCondition gets only reviews assigned to current reviewer
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'proposal')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_reviewer', 'uid', $user->uid, '=');
  $result = $query->execute();

  if (isset($result['node'])) {
    $proposal_ids = array_keys($result['node']);
    $proposals = entity_load('node', $proposal_ids);
    foreach ($proposals as $proposal) {
      $reviewer_proposals[$proposal->nid]['title'] = $proposal->title;
    }
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'review')
      ->propertyCondition('uid', $user->uid) //reviews written by this user
      ->addMetaData('account', user_load(1)); // Run the query as user 1.
    $result = $query->execute();
    if (isset($result['node'])) {
      $review_ids = array_keys($result['node']);
      $reviews = entity_load('node', $review_ids);
      foreach ($reviews as $review) {
        if (isset($review->field_node_reference['und'][0]['nid'])) {
          $reviewed_proposal_id = $review->field_node_reference['und'][0]['nid'];
          if (in_array($reviewed_proposal_id, array_keys($reviewer_proposals))) { // make sure this review is about a proposal
            if (isset($review->field_recommendation['und'][0]['value'])) { // HACK
              // Index of array is node reference field of this review
              $reviewer_proposals[$reviewed_proposal_id]['decision'] = $review->field_recommendation['und'][0]['value'];
              $reviewer_proposals[$reviewed_proposal_id]['review_nid'] = $review->nid;
            }
          }
        }
      }
    }

    $header = array('Title', 'Your Review Decision');
    $rows = array();
    foreach ($reviewer_proposals as $nid => $proposal_info) {
      $reviewed = FALSE;
      if (isset($proposal_info['decision'])) {
        $reviewed = TRUE;
        $decision = $proposal_info['decision'];
      }
      else {
        $decision = "<strong>Not yet reviewed</strong>";
      }
      if ($reviewed) {
        $rows[] = array(l($proposal_info['title'], 'node/' . $nid), $decision . " " . l(" View or edit this review", 'node/' . $proposal_info['review_nid']));
      }
      else {
        $rows[] = array(l($proposal_info['title'], 'node/' . $nid), $decision); // l() HACK
      }
    }

    $output = theme('table', array('header' => $header, 'rows' => $rows ));
  }
  else {
    $output = theme('html_tag', array(
      'element' => array(
      '#tag' => 'h3',
      '#value' => 'You have no proposals assigned to you for review right now. Check back later.',
      ),
    ));
  }

  return $output;
}

/*
 * Page callback for reviewer dashboard for admins
 */
function reviewer_views_dashboard_view() {
  $query = new EntityFieldQuery();
  // Grab all proposals
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'proposal')
    ->propertyCondition('status', 1);
    //->fieldCondition('field_reviewer', 'uid', $user->uid, '=');
  $result = $query->execute();

  if (isset($result['node'])) {
    $proposal_ids = array_keys($result['node']);
    $proposals = entity_load('node', $proposal_ids);
    foreach ($proposals as $proposal) {
      $reviewer_proposals[$proposal->nid]['title'] = $proposal->title;
    }
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'review')
      ->propertyCondition('status', 1);

    $result = $query->execute();
    if (isset($result['node'])) {
      $review_ids = array_keys($result['node']);
      $reviews = entity_load('node', $review_ids);
      foreach ($reviews as $review) {
        if (isset($review->field_node_reference['und'][0]['nid'])) {
          $reviewed_proposal_id = $review->field_node_reference['und'][0]['nid'];
          if (in_array($reviewed_proposal_id, array_keys($reviewer_proposals))) { // make sure this review is about a proposal
            if (isset($review->field_recommendation['und'][0]['value'])) { // HACK
              // Index of array is node reference field of this review
              $reviewer_proposals[$reviewed_proposal_id]['decision'] = $review->field_recommendation['und'][0]['value'];
              $reviewer_proposals[$reviewed_proposal_id]['review_nid'] = $review->nid;
              $user = user_load($review->uid);
              $reviewer_proposals[$reviewed_proposal_id]['reviewer_name'] = l(theme('display_name', (array)$user), 'user/' . $user->uid);

            }
          }
        }
      }
    }

    $header = array('Reviewer', 'Proposal Title', 'Recommendation', 'Final Decision');
    $rows = array();
    foreach ($proposals as $proposal_id => $proposal_info) {
      if (isset($reviewer_proposals[$proposal_id])) {
        $reviewed = TRUE;
        $decision = $reviewer_proposals[$proposal_id]['decision'];
      }
      else {
        $decision = "<strong>Not yet reviewed</strong>";
      }

      $rows[] = array(
        $reviewer_proposals[$proposal_id]['reviewer_name'],
        l($proposal_info->field_proposal_title_2014[LANGUAGE_NONE][0]['value'], 'node/' . $proposal_id),
        $decision . " " . l(" View or edit this review", 'node/' . $reviewer_proposals[$proposal_id]['review_nid']),
        empty($proposal_info->field_final_decision) ? "" : $proposal_info->field_final_decision[LANGUAGE_NONE][0]['value'],
      );
    }

    $output = theme('table', array('header' => $header, 'rows' => $rows ));
  }
  else {
    $output = theme('html_tag', array(
      'element' => array(
      '#tag' => 'h3',
      '#value' => t('There are no outstanding proposals.'),
      ),
    ));
  }

  return $output;
}
