<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP ����  pagecontext.jsp</title>
</head>
<body>
	<h2> pageContext ���� </h2>
	<% pageContext.getOut().println("include.html�� �߰�  "); %>
	<hr>
	<% pageContext.include("include.html"); %>
	
</body>
</html>