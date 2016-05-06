<%
If Request.form("hidden2")="pass" then
	Request.Redirect("won.html")
Else
	Request.Redirect("lost.html")
%>