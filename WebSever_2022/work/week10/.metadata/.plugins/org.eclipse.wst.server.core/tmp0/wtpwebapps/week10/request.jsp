<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%

	request.setCharacterEncoding("euc-kr");


	String npw = request.getParameter("pw");
	String n_name = request.getParameter("name");
	String n_stdNum = request.getParameter("studentNum");
	String nsex = request.getParameter("sex");
	String ncountry = request.getParameter("country");
	
	
	
	out.println("학생 정보 입력 결과" + "<br>");
	out.println("성명 : " + n_name + "<br>");
	out.println("학번 : " + n_stdNum + "<br>");
	
	out.println("성별 : " + nsex + "<br>");
	out.println("국적 : " + ncountry + "<br>");
%>