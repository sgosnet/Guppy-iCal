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


if (stristr($_SERVER['SCRIPT_NAME'], 'uninstall.inc')) {
	header('location:../index.php');
	die();
}


function ap_uninstall() {
	include CHEMIN.'admin/plugins/ical/plugin.inc';
	foreach ($plugin_datas_uninstall['dirs'] as $dir)
		RecursiveRemoteDir(CHEMIN.$dir);
	if (!empty($plugin_datas_uninstall['unreg'])) {
		$regs = ReadDBFields(DBPLUGIN);
		$tmp  = array();
		foreach ($regs as $reg)
			if ($reg[0] != $plugin_datas_uninstall['unreg'])
				$tmp[] = $reg;
		WriteDBFields(DBPLUGIN, $tmp);
	}

	header('location:'.CHEMIN.'admin/admin.php?lng='.$lng);
	die();
}
?>
