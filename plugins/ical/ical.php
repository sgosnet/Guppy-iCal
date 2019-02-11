<?php
/*******************************************************************************
 *   Plugin iCal pour Guppy
 *******************************************************************************
 *   Développé par Stéphane GOSNET
 *   Web site = http://stephane.gosnet.free.fr
 *   e-mail   = stegos@free.fr
 *******************************************************************************
 *   Version  :
 * v1.0 (06/2016) : Version initiale.
 ******************************************************************************/

function dateToCal($timestamp) {
  return date('Ymd\THis\Z', $timestamp);
}

header('Pragma: no-cache');
header('Content-type: text/calendar; charset=utf-8');
header('Content-Disposition: attachment; filename=guppy.ics');
define('CHEMIN', '../../');
include CHEMIN.'inc/includes.inc';
include CHEMIN.'admin/plugins/funcplug.inc';

if (!PluginRegistered('plg_ical')) {
    header('location:../index.php');
    die();
}

if (is_file(CHEMIN.'plugins/ical/'.$lng.'-ical.inc')) {
    include CHEMIN.'plugins/ical/'.$lng.'-ical.inc';
} else {
    include CHEMIN.'plugins/ical/en-ical.inc';
}

$timeZone = $site['TZ'];
$ics_content = "BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//guppy/ical//NONSGML v1.0//EN\nCALSCALE:GREGORIAN\n";

$dbwork = ReadDBFields(DBAGENDA);
@sort($dbwork);

foreach($dbwork as $rdv){
	$date=substr($rdv[0],0,8);
	$horaire=split("-",str_replace(":","",$rdv[1]));
	$id_rdv=$rdv[4];

	ReadDoc($id_rdv);

/* Mon ancien code de transformation du corps de l'agenda
	if($_GET['lang'] == 1)
		$contenu = $fieldc2;
	else
		$contenu = $fieldc1;
	$contenu = strip_tags($contenu);
	$contenu = html_entity_decode($contenu);
	$contenu = preg_replace('~&#x([0-9a-f]+);~ei', 'chr(hexdec("\\1"))', $contenu);
	$contenu = preg_replace('~&#([0-9]+);~e', 'chr("\\1")', $contenu);
	$contenu = preg_replace('/\s\s+/', '||', $contenu); 
*/

// Nouveau code : merci OMT.
	$contenu = str_replace(array("\t", "\"", "&nbsp;"), " ", ($_GET['lang'] == 1 ? $fieldc2:$fieldc1)); 
	$html_reg = array('@<script[^>]*?>.*?</script>@si',  // Strip out javascript
			'@<[\/\!]*?[^<>]*?>@si',            // Strip out HTML tags
			'@<style[^>]*?>.*?</style>@siU'    // Strip style tags properly
	); 
	$contenu = preg_replace($html_reg, '', $contenu) ;		

	$html_reg = array('/\s\s+/');         // Strip multi-line comments including CDATA
	$contenu = preg_replace($html_reg, '||', $contenu) ;		
	
	$champs = explode('||',$contenu,3);
	$champs[2] = str_replace("||","\\n",$champs[2]);

	$ics_content = $ics_content."BEGIN:VEVENT\n";
	$ics_content = $ics_content."UID:$id_rdv\n";
	$ics_content = $ics_content."DTSTAMP:".dateToCal(time())."\n";
	$ics_content = $ics_content."SUMMARY:$champs[0]\n";
	$ics_content = $ics_content."LOCATION:$champs[1]\n";
	$ics_content = $ics_content."DESCRIPTION:$champs[2]\n";

	if($horaire[0] && $horaire[1]){
		$ics_content = $ics_content."DTSTART;TZID=$timeZone:".$date."T".$horaire[0]."00\n";
		$ics_content = $ics_content."DTEND;TZID=$timeZone:".$date."T".$horaire[1]."00\n";
	}else{
		$ics_content = $ics_content."DTSTART;VALUE=DATE:$date\n";
		$ics_content = $ics_content."DTEND;VALUE=DATE:$date\n";
	}

	$ics_content = $ics_content."END:VEVENT\n";
}
$ics_content = $ics_content."END:VCALENDAR\n";
echo $ics_content;
?>

