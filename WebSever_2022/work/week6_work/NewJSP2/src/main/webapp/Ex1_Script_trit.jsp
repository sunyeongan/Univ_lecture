<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>JSP 예제 scripttlet.jsp</title>
</head>
<body>

	<% int i = 24; %>
	<%
	
		out.println("하루는" + i + "시간이며 , <br>");
		out.println("하루는" + i*60 + "분입니다.");
	%>

</body>
</html>