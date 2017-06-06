<?php
/**
 * @file
 * Settings forms the for Commerce EMS Russian Post module.
 */


/**
 * Form callback: builds the settings form.
 *
 * Used to collect API credentials and enable supported shipping services.
 */
function deli_admin_form($form, &$form_state) {

  $form['modeId'] = array(
    '#type' => 'select',
    '#title' => t('Режимы доставки'),
    '#description' => t('Доставка для клиента'),
    '#options' => array(
        1 => 'Курьер забирает груз у отправителя и доставляет получателю на указанный адрес.',
        2 => 'Курьер забирает груз у отправителя и довозит до склада, получатель забирает груз самостоятельно в ПВЗ (самозабор).'
    ),
    '#default_value' => variable_get('modeId', 1),
  );

  $form['oplata_kureru'] = array(

    '#type' => 'textfield',

    '#title' => t('Доставка'),

    '#default_value' => variable_get('oplata_kureru', 0),

    '#size' => 60,

    '#description' => t('Какую сумму плясовать к доставке'),


  );

  $form['tarifid'] = array(
    '#type' => 'select',
    '#title' => t('Тариф'),
    '#description' => t('Выбрать тариф'),
    '#options' => array(
        1 => 'Экспресс лайт дверь-дверь',
        3 => 'Супер-экспресс до 18',
        10 => 'Экспресс лайт склад-склад',
        5 => 'Экономичный экспресс склад-склад'
    ),
    '#default_value' => variable_get('tarifid', 1),
  );



  $form['mini'] = array(

    '#type' => 'fieldset',
    '#title' => t('Рулонные шторы мини'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,

  );


        $form['mini']['from'] = array(

          '#type' => 'item',
          '#title' => t('Рулонные шторы мини'),
          '#markup' => 'Среднии значения для штор мини',

        );
        $form['mini']['mini_weight'] = array(
          '#default_value' => variable_get('mini_weight', ''),
          '#type' => 'textfield',
          '#title' => t('Вес рулонной шторы мини'),
          '#description' => t('Вес в кг'),

        );
        $form['mini']['mini_length'] = array(
          '#default_value' => variable_get('mini_length', ''),
          '#type' => 'textfield',
          '#title' => t('Длинна рулонной шторы мини'),
          '#description' => t('Длинна в см'),

        );
        $form['mini']['mini_width'] = array(
          '#default_value' => variable_get('mini_width', ''),
          '#type' => 'textfield',
          '#title' => t('Ширина рулонной шторы мини'),
          '#description' => t('Ширина в см'),
        );
        $form['mini']['mini_height'] = array(
          '#default_value' => variable_get('mini_height', ''),
          '#type' => 'textfield',
          '#title' => t('Высота рулонной шторы мини'),
          '#description' => t('Высота в см'),

        );


  $form['standart'] = array(

    '#type' => 'fieldset',
    '#title' => t('Рулонные шторы стандарт'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,

  );


        $form['standart']['from'] = array(

          '#type' => 'item',
          '#title' => t('Рулонные шторы стандарт'),
          '#markup' => 'Среднии значения для штор стандарт',

        );
        $form['standart']['standart_weight'] = array(
          '#default_value' => variable_get('standart_weight', ''),
          '#type' => 'textfield',
          '#title' => t('Вес рулонной шторы стандарт'),
          '#description' => t('Вес в кг'),

        );
        $form['standart']['standart_length'] = array(
          '#default_value' => variable_get('standart_length', ''),
          '#type' => 'textfield',
          '#title' => t('Длинна рулонной шторы стандарт'),
          '#description' => t('Длинна в см'),

        );
        $form['standart']['standart_width'] = array(
          '#default_value' => variable_get('standart_width', ''),
          '#type' => 'textfield',
          '#title' => t('Ширина рулонной шторы стандарт'),
          '#description' => t('Ширина в см'),
        );
        $form['standart']['standart_height'] = array(

          '#type' => 'textfield',
          '#title' => t('Высота рулонной шторы стандарт'),
          '#description' => t('Высота в см'),
          '#default_value' => variable_get('standart_height', ''),
        );





 /* $form['commerce_ems_packege_max_weight'] = array(
    '#markup' => t('Max package weight for Ems: @weight kg', array('@weight' => commerce_ems_get_max_weight())),
  );*/

 return system_settings_form($form);
}
