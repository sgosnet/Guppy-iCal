<?php
/*
	Plugin Version : Plugin for GuppY 4.5
	under CeCILL v2 Free Software Agreement
	Copyright (C) 2006-2007 by  HPSAM
	Web site = http://www.hpsam.info
	Adapté par Lud Bienaimé pour l'encodage en UTF-8 et le HTML5 
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'update.inc')) {
	header('location:../index.php');
	die();
}

$repPlugin = 'admin/plugins/'.substr($plug, 0, strpos($plug, '/') + 1);

include CHEMIN.$repPlugin.'version/version.inc';
if (is_file(CHEMIN.$repPlugin.'version/'.$lng.'-pvlang.inc'))
	include CHEMIN.$repPlugin.'version/'.$lng.'-pvlang.inc';
else
	include CHEMIN.$repPlugin.'version/en-pvlang.inc';

$version['errors'] = "";
$version['ok']     = "";
$load_ok           = false;
$lines             = array();

if (ini_get('allow_url_fopen')) {
	$lines   = @file($version['url']);
	$load_ok = true;
}
elseif ($curl = @curl_init($version['url'])){
	$timeout = 5; // set to zero for no timeout
	curl_setopt ($curl, CURLOPT_CONNECTTIMEOUT, $timeout);
	curl_setopt ($curl, CURLOPT_RETURNTRANSFER, 1);
	$version_content = curl_exec($curl);
	curl_close($curl);
	if ($version_content != false) {
		$lines = explode("\n", $version_content);
		$load_ok=true;
	}
}
else {
	$version['errors'] = $pv_error1;
}
if ($load_ok) {
	$version['latest'] = trim($lines[0]);

	switch ($version['latest']){
		case '': $version['errors'] = $pv_error2; break;
		case 'error3': $version['errors'] = $pv_error3; break;
		case 'error4': $version['errors'] = $pv_error4; break;
		case 'error5': $version['errors'] = $pv_error5; break;
		default:
		  if (version_compare($version['current'], $version['latest']) < 0) {
    		$pv_ok = $pv_ok1.'<br /><a href="'.trim($lines[2]).'" target="_blank" title="'.$pv_ok1.'">'.$pv_ok2.$version['latest'].$pv_ok3.trim($lines[1]).'</a>';
				$version['ok'] = $pv_ok;
  		}
  		else {
			  $version['ok'] = $pv_ok4;
  		}
	}
}
?>