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

# Securité
if (stristr($_SERVER['SCRIPT_NAME'], 'ical.inc')) {
    header('location:../index.php');
    die();
}

# Désinstallation
$uninstall = import('uninstall');
if ($uninstall == 'on') {
	include CHEMIN.'admin/plugins/ical/uninstall.inc';
	ap_uninstall();
}

# Fichier de langue et fonctions
if (is_file(CHEMIN.'plugins/ical/'.$lng.'-ical.inc')) {
    include CHEMIN.'plugins/ical/'.$lng.'-ical.inc';
} else {
    include CHEMIN.'plugins/ics/en-ical.inc';
}

include("plugins/funcplug.inc");
include("version/update.inc");

# Activation du plugin
$plg_ical = import('plg_ical');
if ($regit == 1) {
    if ($plg_ical == 'on') {
        if (!PluginRegistered('plg_ical')) {
            RegisterPlugin('plg_ical','ALL','ALL');
        }
    }
    else {
        UnregisterPlugin('plg_ical');
    }
}

# Affichage :

# Top
$topmess = '<a href="admin.php?lng='.$lng.'">Admin</a> > '.str_replace('Admin - ', '', $ical[1]);
include CHEMIN.'admin/hpage.inc';
if ($wri == 'admin') include CHEMIN.'admin/administrateur.php';
if ($wri == $userprefs[1]) include CHEMIN.'admin/adminredac.php';
htable($ical[1], '100%');

# Corps configuration
echo '
<form name="ics" action="admin.php?lng='.$lng.'&amp;pg=plugin&amp;plug=ical/ical" method="post">
  <input type="hidden" name="regit" value="1" />
  <fieldset style="width:75%; margin:0 auto;">
    <p>'.$ical[3].'</p>
    <p>'.$ical[7].'</p>
    <p style="text-align:center">'.$ical[4].'&nbsp;&nbsp;<input type="checkbox" name="plg_ical"'.Checked(PluginRegistered("plg_ical")).' /></p>
    <p style="text-align:center">'.SubmitButton($admin[66]).'</p>
  </fieldset>
</form>
<hr />';

# Corps Lien iCal
if(PluginRegistered('plg_ical')){
    echo '
    <p style="text-align:center"><img src='.CHEMIN.'inc/lang/'.$lng.'.gif />'.$ical[5].' '.$site[3].'plugins/ical/ical.php</p>';

    if($lang[1]){
        echo '
        <p style="text-align:center"><img src='.CHEMIN.'inc/lang/'.$lang[1].'.gif />'.$ical[6].' '.$site[3].'plugins/ical/ical.php?lang=1</p>';
    }
}

# Info version
echo '
<hr />
<div style="margin:20px;text-align:center;">
	<p>iCal &copy; Stephane GOSNET</p>
	<p>v'.$version['current'].' - '.$version['date'].'</p>
	<p>'.$version['errors'].$version['ok'].'</p>
</div>
';


# Coprs désinstallation
echo '
<div style="margin:20px;text-align:center;">
  <form name="uninst" action="admin.php?lng='.$lng.'&amp;pg=plugin&amp;plug=ical/ical" method="POST">
	<input type="hidden" name="uninstall" value="on" />
	'.SubmitButton($ical[20]).'
  </form>
</div>
<hr />';

# Bas de page
echo '
<p style="text-align:center"><a href="admin.php?lng='.$lng.'">'.$admin[22].'</a> || <b><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin[19].'</a></b></p>';

btable();
include CHEMIN.'admin/bpage.inc';
