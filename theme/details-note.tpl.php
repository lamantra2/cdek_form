<?php
/**
 * @file
 * Template file ems service details note.
 *
 * Available variables:
 * - $formatted_price - formatted price on delivery
 * - $period - delivery period
 */
//dsm($error_text);
?>
<?php if(isset($error_text)) : ?>

  <div class="commerce-ems-service-details-note">
     <?php print $error_text?>
  </div>


<?php else: ?>

<div class="commerce-ems-service-details-note">
  <?php print t('Орентировачная стоимость доставки: @price', array('@price' => $price)); ?>,</br>
  <?php print t('Минимальный срок доставки: @min_period', array('@min_period' => $min_period)); ?>,</br>
  <?php print t('Максимальный срок доставки: @max_period', array('@max_period' => $max_period)); ?>
</div>

<?php endif; ?>
