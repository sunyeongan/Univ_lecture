<%@page import="java.util.Enumeration"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP ���� request3.jsp</title>
</head>
<body>

	<% 
		request.setCharacterEncoding("euc-kr"); 
	%>
	
<h2> ��̿� ������ ���� ���� ��� </h2>
	<%
		Enumeration<String> e = request.getParameterNames();
		while( e.hasMoreElements() ) {
			String name = e.nextElement();
			String[] data = request.getParameterValues(name);
			
			if(data != null) {
				for(String str : data) 
					out.println(str + " ");
			} 
			out.println("<p>");
		}
	%>
	
	
</body>
</html>