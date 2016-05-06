<?php
session_start();
if(!is_numeric($_SESSION['team_no']))
{
	header("location: index.php");
}
$db = mysql_connect("localhost","root","");
mysql_select_db("beer_db");
$o_out = $_POST['order_out'];
$d_out = $_POST['del_out'];
$team_no = $_SESSION['team_no'];
function execute_query ($query)
{
	$result = mysql_query($query);
	return $result;
}
$cur_week_arr = mysql_fetch_array(execute_query("SELECT * FROM `current_week`"));
$cur_week = $cur_week_arr['week'];
$reaching_week = $cur_week+2;
$result_o_in = execute_query("SELECT `order_out` FROM `admin_customer` WHERE `order_out_week` = '$cur_week'");
if($result_o_in)
{
	$o_in_arr = mysql_fetch_array($result_o_in);
	$o_in = $o_in_arr['order_out'];
	if($d_out > $o_in)
	{
		$_SESSION['error'] = "Invalid delivery!";
		header("location: retailer_main.php");
		die();
	}
}
else
{
	$o_in = 0;
	if($d_out > 0)
	{
		$_SESSION['error'] = "Invalid delivery!";
		header("location: retailer_main.php");
		die();
	}
}
$result_d_in = execute_query("SELECT `del_out` FROM `wholesaler"."$team_no"."` WHERE `del_out_week` = '$cur_week'");
if($result_d_in)
{
	$d_in_arr = mysql_fetch_array($result_d_in);
	$d_in = $d_in_arr['del_out'];
}
else
{
	$d_in = 0;
}
$prev_week = $cur_week - 1;
if($prev_week > 0)
{
	$avail_arr = mysql_fetch_array(execute_query("SELECT `available` FROM `retailer"."$team_no"."` WHERE `week`='$prev_week'"));
	$avail = $avail_arr['available'];
	$pending_arr = mysql_fetch_array(mysql_query("SELECT `pending_order` FROM `retailer"."$team_no"."` WHERE `week`='$prev_week'"));
	$pending = $pending_arr['pending_order'];
}
else
{
	$avail = 12;
	$pending = 0;
}
if($d_out > ($avail + $d_in))
{
	$_SESSION['error'] = "Invalid delivery!";
	header("location: retailer_main.php");
	die();
}
if($d_out < ($o_in + $pending))
{
	$pending = $pending + $o_in - $d_out;
}
else
{
	$pending = 0;
}
$avail = $avail + $d_in - $d_out;
if($avail > 0)
{
	$cur_hold_cost = $avail * 0.5;
}
else if($avail < 0)
{
	$_SESSION['error'] = "Invalid delivery!";
	header("location: retailer_main.php");
	die();
}
else
{
	$cur_hold_cost = 0;
}
if($pending != 0)
{
	$cur_back_cost = $pending;
}
else
{
	$cur_back_cost = 0;
}
$cur_cost = $cur_hold_cost + $cur_back_cost;
if($prev_week > 0)
{
	$tot_cost_arr = mysql_fetch_array(execute_query("SELECT `total_cost` FROM `retailer"."$team_no"."` WHERE `week`='$prev_week'"));
	$tot_cost = $tot_cost_arr['total_cost'];
}
else
{
	$tot_cost = 0;
}
$total_cost = $tot_cost + $cur_cost;
if($d_out>$o_in)
{
	$_SESSION['error'] = "Invalid delivery!";
	header("location: retailer_main.php");
	die();
}
if($avail<0)
{
	$_SESSION['error'] = "Invalid delivery!";
	header("location: retailer_main.php");
	die();
}
execute_query("INSERT INTO `retailer"."$team_no"."` (`week`,`order_out`,`del_out`,`order_out_week`,`order_in`,`del_in`,`available`,`current_week_cost`,`total_cost`,`pending_order`) VALUES ('$cur_week','$o_out','$d_out','$reaching_week','$o_in','$d_in','$avail','$cur_cost','$total_cost','$pending')");
//execute_query("UPDATE `week_cnt"."$team_no"."` SET `week`='1' WHERE `role`='retailer'");
//$cur_role = "retailer";
//header("location: complete_week.php?cur_role=retailer");
header("location: wait.php?role=retailer");
die();
?>