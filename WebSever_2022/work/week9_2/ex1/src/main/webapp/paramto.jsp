<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");
	
	String nko = request.getParameter("ko");
	String nam = request.getParameter("am");
	
	out.println("������ ó�� ��� �Դϴ�.<br>");
	
	out.println("���۵� ko�� " + nko + "�Դϴ�. <br>");
	out.println("���۵� mo�� " + nam + "�Դϴ�. <br>");
	
%>
	