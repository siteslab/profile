<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <?php if ($linked_logo_img || $site_name || $site_slogan): ?>
    <div class="branding-data clearfix">
      <?php if ($linked_logo_img): ?>
	  
      <div class="logo-img">

<?php
$theme = alpha_get_theme();
$vars['title'] = $theme->page['title'];
$vars['base_path'] = $theme->page['base_path'];
?>
	  
<?php switch(strtolower($vars['title'])): ?>
<?php case('about enculturation'); case('submission guidelines'); case('editors'); case('frequently asked questions'); case('book reviews'); ?>


<?php break; ?>
<?php endswitch; ?>
	  
        <!-- <?php print $linked_logo_img; ?> -->
      </div>
	  
	  <?php endif; ?>
	  
      <?php if ($site_name || $site_slogan): ?>
      <?php $class = $site_name_hidden && $site_slogan_hidden ? ' element-invisible' : ''; ?>
      <hgroup class="site-name-slogan<?php print $class; ?>">        
        <?php if ($site_name): ?>
        <?php $class = $site_name_hidden ? ' element-invisible' : ''; ?>
        <?php if ($is_front): ?>        
        <h1 class="site-name<?php print $class; ?>"><?php print $linked_site_name; ?></h1>
        <?php else: ?>
        <h2 class="site-name<?php print $class; ?>"><?php print $linked_site_name; ?></h2>
        <?php endif; ?>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
        <?php $class = $site_slogan_hidden ? ' element-invisible' : ''; ?>
        <h6 class="site-slogan<?php print $class; ?>"><?php print $site_slogan; ?></h6>
        <?php endif; ?>
      </hgroup>
      <?php endif; ?>
    </div>
    <?php endif; ?>
    <?php print $content; ?>
  </div>
</div>
