<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>JSP 예제 membervar.jsp</title>
</head>
<body>
	<% int i = 0; %>
	[지역변수] i = <%= ++i %>
	<p>
	[소속변수] memi = <%= ++memi %>
	<%! int memi = 0;%>

</body>
</html>