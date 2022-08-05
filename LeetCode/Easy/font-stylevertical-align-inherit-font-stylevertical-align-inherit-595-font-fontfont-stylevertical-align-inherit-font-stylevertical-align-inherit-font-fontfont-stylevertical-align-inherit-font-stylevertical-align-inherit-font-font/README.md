<h2><a href="https://leetcode.com/problems/big-countries"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">595 </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">. </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">큰 나라</font></font></a></h2><h3>Easy</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">SQL 스키마</font></font><svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">테이블:</font></font><code>World</code></p>

<pre>+-------------+---------+<font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">열 이름 | </font><font style="vertical-align: inherit;">유형 |</font></font><font></font>
+-------------+---------+<font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">이름 | </font><font style="vertical-align: inherit;">바르챠 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">대륙 | </font><font style="vertical-align: inherit;">바르챠 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">지역 | </font><font style="vertical-align: inherit;">정수 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">인구 | </font><font style="vertical-align: inherit;">정수 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">gdp | </font><font style="vertical-align: inherit;">정수 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
+-------------+---------+</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
name은 이 테이블의 기본 키 열입니다.</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
이 표의 각 행은 국가 이름, 국가가 속한 대륙, 면적, 인구 및 GDP 값에 대한 정보를 제공합니다.</font></font><font></font>
</pre>

<p>&nbsp;</p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">국가는 다음과 같은 경우 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">큰</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 것입니다 .</font></font></p>

<ul>
	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">면적이 300만(즉, </font><font style="vertical-align: inherit;">) 이상이거나</font></font><code>3000000 km<sup>2</sup></code><font style="vertical-align: inherit;"></font></li>
	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">인구가 최소 2천 5백만 명(즉, </font></font><code>25000000</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">)입니다.</font></font></li>
</ul>

<p><font style="vertical-align: inherit;"></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">큰 국가</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 의 이름, 인구 및 면적을 보고하는 SQL 쿼리를 작성하십시오 </font><font style="vertical-align: inherit;">.</font></font></p>

<p><font style="vertical-align: inherit;"></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">임의의 순서</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 로 결과 테이블을 반환합니다 </font><font style="vertical-align: inherit;">.</font></font></p>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">쿼리 결과 형식은 다음 예와 같습니다.</font></font></p>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">예 1:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">입력:</font></font></strong> <font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
세계 테이블:</font></font><font></font>
+-------------+-----------+---------+------------+--------------+<font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">이름 | </font><font style="vertical-align: inherit;">대륙 | </font><font style="vertical-align: inherit;">지역 | </font><font style="vertical-align: inherit;">인구 | </font><font style="vertical-align: inherit;">gdp |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
+-------------+-----------+---------+------------+--------------+</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">아프가니스탄 | </font><font style="vertical-align: inherit;">것 | </font><font style="vertical-align: inherit;">652230 | </font><font style="vertical-align: inherit;">25500100 | </font><font style="vertical-align: inherit;">20343000000 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">알바니아 | </font><font style="vertical-align: inherit;">유럽 ​​| </font><font style="vertical-align: inherit;">28748 | </font><font style="vertical-align: inherit;">2831741 | </font><font style="vertical-align: inherit;">12960000000 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">알제리 | </font><font style="vertical-align: inherit;">아프리카 | </font><font style="vertical-align: inherit;">2381741 | </font><font style="vertical-align: inherit;">37100000 | </font><font style="vertical-align: inherit;">188681000000 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">안도라 | </font><font style="vertical-align: inherit;">유럽 ​​| </font><font style="vertical-align: inherit;">468 | </font><font style="vertical-align: inherit;">78115 | </font><font style="vertical-align: inherit;">3712000000 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">앙골라 | </font><font style="vertical-align: inherit;">아프리카 | </font><font style="vertical-align: inherit;">1246700 | </font><font style="vertical-align: inherit;">20609294 | </font><font style="vertical-align: inherit;">100990000000 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
+-------------+-----------+---------+------------+--------------+</font></font><font></font>
<strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">산출:</font></font></strong> <font></font>
+-------------+------------+---------+<font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">이름 | </font><font style="vertical-align: inherit;">인구 | </font><font style="vertical-align: inherit;">지역 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
+-------------+------------+---------+</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">아프가니스탄 | </font><font style="vertical-align: inherit;">25500100 | </font><font style="vertical-align: inherit;">652230 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
| </font><font style="vertical-align: inherit;">알제리 | </font><font style="vertical-align: inherit;">37100000 | </font><font style="vertical-align: inherit;">2381741 |</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
+-------------+------------+---------+</font></font><font></font>
</pre>
</div>