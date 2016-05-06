<?php
session_start();
if(isset($_SESSION['error']))
{
	echo $_SESSION['error'];
	unset($_SESSION['error']);
}
?>
<html>
<head>
	<title>Home Page</title>
	<script type="text/javascript">
	function get_team_no()
	{
		team_no = window.prompt("Enter your team number:");
		document.cookie = "team_no=" + team_no + ";";
	}
	</script>
	<style>
	#help
	{
		position:absolute;
		margin-left:15%;
		margin-top:-1%;
		width:5%;
		height:5%;
		transform:rotate(25deg);
		-webkit-transform:rotate(25deg);
	}
	
	#play
	{
		position:absolute;
		margin-left:30%;
		margin-top:2%;
		width:10%;
		height:25%;
	}
	
	#quit
	{
		position:absolute;
		margin-left:45%;
		margin-top:1%;
		width:5%;
		height:5%;
		transform:rotate(-25deg);
		-webkit-transform:rotate(-25deg);
	}
	</style>
</head>
<body background="bgimg.jpg">
<div style="margin-left:22%">
	<font color="#FFa500" size="15"><u>BEER GAME</u>.....!!!</font>
</div>

<div id="help">
	<a href="help.html"><img src="help.jpg" alt="HELP" /></a>
</div>

<div id="play" onmouseover="document.getElementById('players').style.display = 'block';" onmouseout="document.getElementById('players').style.display = 'none';">
	<img src="play.jpg" alt="PLAY" />

<div id="players" style="display: none; margin-left:10%; margin-top:6%; width:50% position:absolute;">
	<font face="Copperplate Gothic Bold" size="4.5px" color="#aaaaaa">
	<br />
	<a href="administrator_main.php" style="color:#333300;">Admin</a><br/>
	<!---<a href="retailer_main.php?team_no=" +team_no style="color:#330033;">Retailer</a><br/>
	<a href="wholesaler_main.php" style="color:#330033;">Wholesaler</a><br/>
	<a href="distributer_main.php" style="color:#330033;">Distributer</a><br/>
	<a href="factory_main.php" style="color:#330033;">Factory</a><br/>--->
	<a href="players.php" style="color:#333300;" onclick="get_team_no()">Players</a><br/>
	</font>
	
</div>
</div>

<div id="quit">
	<a href="quit.html"><img src="quit.jpg" alt="QUIT" /></a>
</div>

</body>
</html>
