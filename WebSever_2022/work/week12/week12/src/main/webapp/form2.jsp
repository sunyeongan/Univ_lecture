<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

	<h2>JavaBeans를 이용한 학새으이 점수에 따른 성적 처리 예제 </h2>
	<%request.setCharacterEncoding("euc-kr"); %>
	<jsp:useBean id = "stu" class="week12.stuBean" scope="page"/>
	<HR>
	
	<h3>폼에서 전달받은 학생정보를 그대로 자바빈 StudentBean에 저장 </h3><p>
	<jsp:setProperty  name = "stu" property = "id" param="id"/>
	<jsp:setProperty  name = "stu" property = "sname" param="sname"/>
	<jsp:setProperty  name = "stu" property = "call" param="call"/>
	<jsp:setProperty  name = "stu" property = "year" param="choice"/>
	
	<jsp:setProperty  name = "stu" property = "pw" param="pw"/>
	<jsp:setProperty  name = "stu" property = "mail" param="mail"/>
	
	<HR>
	<h3>JavaBean StudentBean에 저장된 정보를 조회 출력 </h3>
	학생 ID : <jsp:getProperty name = "stu" property="id"/><BR> 
	학생 이름 : <jsp:getProperty name = "stu" property="sname"/><BR> 
	학생 번호 : <jsp:getProperty name = "stu" property="call"/><BR>
	학생 나이 : <jsp:getProperty name = "stu" property="age"/>(<jsp:getProperty name = "stu" property="year"/>)<BR> 
	암호  : <jsp:getProperty name = "stu" property="pw"/><BR> 
	전자메일  : <jsp:getProperty name = "stu" property="mail"/><BR> 
	
</body>
</html>