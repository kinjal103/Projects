<?php
if(!(is_numeric($_COOKIE['team_no'])))
{
	header("location: index.php");
}
?>
<html>
<head>
	<title>Players</title>
	<style>
		#retailer
		{
			position:absolute;
			margin-left:1%;
			margin-top:5%;
			width:15%;
			height:10%;	
		}
		
		#wholesaler
		{
			position:absolute;
			margin-left:15%;
			margin-top:5%;
			width:15%;
			height:10%;	
		}
		
		#distributor
		{
			position:absolute;
			margin-left:34%;
			margin-top:5%;
			width:15%;
			height:10%;	
		}
		
		#factory
		{
			position:absolute;
			margin-left:52%;
			margin-top:5%;
			width:15%;
			height:10%;	
		}
	</style>
</head>
<body background="bgimg.jpg">

<font face="Copperplate Gothic Bold" size="10%">
<div style="margin-left:5%; height:12%; width:50%; position:absolute;">You would like to be..</div>
</font>
<div>
	<div id="retailer">
	<font face="Copperplate Gothic Bold" size="6%">
		<a href="retailer_main.php">Retailer</a>
	</font>
	</div>
	
	<div id="wholesaler">
	<font face="Copperplate Gothic Bold" size="6%">
	<a href="wholesaler_main.php">Wholesaler</a>
	</font>
	</div>
	
	<div id="distributor">
	<font face="Copperplate Gothic Bold" size="6%">
	<a href="distributor_main.php">Distributor</a>
	</font>
	</div>
	
	<div id="factory">
	<font face="Copperplate Gothic Bold" size="6%">
	<a href="factory_main.php">Factory</a>
	</font>
	</div>
</div>
<?php session_start(); $_SESSION['team_no'] = $_COOKIE['team_no'];
$con = mysql_connect("localhost","root","");
$db = mysql_select_db("beer_db");
$team_no = $_SESSION['team_no'];
$cur_team_arr = mysql_fetch_array(mysql_query("SELECT * FROM `teams` WHERE `team_no`='$team_no'"));
if($cur_team_arr['full']==1)
{
	$_SESSION['error'] = "Team is already full, choose another";
	header("location: index.php");
	die();
}
else
{
	echo "Available roles for this team are:";
	if($cur_team_arr['retailer']==0)
	{
		echo "Retailer";
	}
	if($cur_team_arr['wholesaler']==0)
	{
		echo "Wholesaler";
	}
	if($cur_team_arr['distributor']==0)
	{
		echo "Distributor";
	}
	if($cur_team_arr['factory']==0)
	{
		echo "Factory";
	}
}
?>
</body>
</html>
