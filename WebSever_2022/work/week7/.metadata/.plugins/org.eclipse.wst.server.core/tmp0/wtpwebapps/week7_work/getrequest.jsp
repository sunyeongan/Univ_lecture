<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP ���� getrequest.jsp</title>
</head>
<body>

	<% 
		request.setCharacterEncoding("euc-kr"); 
	%>
	
<h2> �޼ҵ� get ��Ŀ��� �ѱ� ó�� </h2>
�ѱ� ���� : <%= request.getParameter("korname") %> <p>
���� ���� : <%= request.getParameter("engname") %> <p>
	
	
</body>
</html>

