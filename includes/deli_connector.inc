<?php

function calculate_rate($to, $goods, $tarif, $modeId){

$oplata_kureru = variable_get('oplata_kureru', '');
$modeId = variable_get('modeId', 1);
$tarif  = variable_get('tarifid', 1);

  $ar = array(
      "version" => "1.0",

      "senderCityId" => '1214',
      "receiverCityId" => $to,
      "tariffId" => $tarif,
      "modeId" => $modeId,
       "goods" => $goods
);

//dsm($ar);
  $j = json_encode($ar);
   $result = drupal_http_request('http://api.edostavka.ru/calculator/calculate_price_by_json.php', array(
    'headers' => array('Content-Type' => 'application/json'),
    'method' => 'POST',
    'data' => $j,
  ));

 if($result){
  $cart = json_decode( $result->data );
 }

//dsm($cart);


if(isset($cart->error)){
  return (object) array(
  'error_text' => $cart->error[0]->text,
  );

}else{
return (object) array(
    'status' => TRUE,
    'price' => ($oplata_kureru > 0) ? $cart->result->price + $oplata_kureru : $cart->result->price,
    'currency' => $cart->result->currency,
    'min_period' => $cart->result->deliveryPeriodMin,
    'max_period' => $cart->result->deliveryPeriodMax,
    'min_delivery_date' => $cart->result->deliveryDateMin,
    'max_delivery_date' => $cart->result->deliveryDateMax,
  );
}



}




    /* "goods" => array(
            array(
              "weight" => "0.3",
              "length" => "10",
              "width" => "7",
              "height" => "5"
              ),
            array(
              "weight" => "0.1",
              "volume" => "0.1"
              ),
          ),*/
