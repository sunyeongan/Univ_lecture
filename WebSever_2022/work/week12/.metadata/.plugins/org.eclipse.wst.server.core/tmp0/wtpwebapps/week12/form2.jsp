<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

	<h2>JavaBeans�� �̿��� �л����� ������ ���� ���� ó�� ���� </h2>
	<%request.setCharacterEncoding("euc-kr"); %>
	<jsp:useBean id = "stu" class="week12.stuBean" scope="page"/>
	<HR>
	
	<h3>������ ���޹��� �л������� �״�� �ڹٺ� StudentBean�� ���� </h3><p>
	<jsp:setProperty  name = "stu" property = "id" param="id"/>
	<jsp:setProperty  name = "stu" property = "sname" param="sname"/>
	<jsp:setProperty  name = "stu" property = "call" param="call"/>
	<jsp:setProperty  name = "stu" property = "year" param="choice"/>
	
	<jsp:setProperty  name = "stu" property = "pw" param="pw"/>
	<jsp:setProperty  name = "stu" property = "mail" param="mail"/>
	
	<HR>
	<h3>JavaBean StudentBean�� ����� ������ ��ȸ ��� </h3>
	�л� ID : <jsp:getProperty name = "stu" property="id"/><BR> 
	�л� �̸� : <jsp:getProperty name = "stu" property="sname"/><BR> 
	�л� ��ȣ : <jsp:getProperty name = "stu" property="call"/><BR>
	�л� ���� : <jsp:getProperty name = "stu" property="age"/>(<jsp:getProperty name = "stu" property="year"/>)<BR> 
	��ȣ  : <jsp:getProperty name = "stu" property="pw"/><BR> 
	���ڸ���  : <jsp:getProperty name = "stu" property="mail"/><BR> 
	
</body>
</html>