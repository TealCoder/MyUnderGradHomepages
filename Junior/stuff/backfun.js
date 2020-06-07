var color=0;
var inc = 1;
/******************************
 * Java Script Background Fun *
 *        by Sean Head        *
 ******************************/
var bgrounds = new Array(
"a3ffff","a7fbff","abf7ff","aff3ff",
"b3efff","b7ebff","bbe7ff","bfe3ff",
"c3dfff","c7dbff","cbd7ff","cfd3ff",
"d3cfff","d7cbff","dbc7ff","dfc3ff",
"e3bfff","e7bbff","ebb7ff","efb3ff",
"f3afff","f7abff","fba7ff","ffa3ff",
"ffa3ff","ffa7fb","ffabf7","ffaff3",
"ffb3ef","ffb7eb","ffbbe7","ffbfe3",
"ffc3df","ffc7db","ffcbd7","ffcfd3",
"ffd3cf","ffd7cb","ffdbc7","ffdfc3",
"ffe3bf","ffe7bb","ffebb7","ffefb3",
"fff3af","fff7ab","fffba7","ffffa3",
"ffffa3","fbffa7","f7ffab","f3ffaf",
"efffb3","ebffb7","e7ffbb","e3ffbf",
"dfffc3","dbffc7","d7ffcb","d3ffcf",
"cfffd3","cbffd7","c7ffdb","c3ffdf",
"bfffe3","bbffe7","b7ffeb","b3ffef",
"affff3","abfff7","a7fffb","a3ffff");

function rotate()
{
  if (color >= bgrounds.length - 1) inc = -1;
  if (color <= 0) inc = 1;
  color += inc;
  document.bgColor = bgrounds[color];
  setTimeout("rotate()", 100);
}
