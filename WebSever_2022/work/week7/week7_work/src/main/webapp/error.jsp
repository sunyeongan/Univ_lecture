<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP ���� bufferoverflow.jsp</title>
</head>
<body>
	<%@ page isErrorPage="true" %>
	<h1> ����ó�� ������ </h1>
	���� ���ڿ�[exception.toString()] : <%= exception.toString() %> <p>
	���� �޼���[exception.getMessage()] : <%= exception.getMessage() %>
	
</body>
</html>