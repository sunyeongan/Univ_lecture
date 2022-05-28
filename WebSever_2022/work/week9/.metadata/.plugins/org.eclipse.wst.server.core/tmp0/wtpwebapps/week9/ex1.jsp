<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

<%
	request.setCharacterEncoding("euc-kr");
%>

<%

	String name = request.getParameter("name");
	String passwd = request.getParameter("passwd");
%>


이름 : <%= name %><p>
비밀번호 : <%=passwd %><p>
</body>
</html>