<h1>RSHELL</h1>
<h4>By Jamal M. Moon</h4>
======

<h2>Table of Contents</h2>
<ol>
    <li><a href="#introTag">Introduction</a></li>
    <li><a href="#featuresTag">Features</a></li>
    <li><a href="#howToGetTag">How To Install</a></li>
    <li><a href="#bugsTag">Known Bugs/Limitation</a></li>
</ol>

<h1><a name="introTag">Introduction</a></h1>

This project contains the rudimentary foundation for a shell. While limited, it can execute a number of bash commands with proper arguments, syntax, and connector operations.

<h1><a name="featuresTag">Features</a></h1>

<ul>
    <li>Can execute a plethora of bash commands: echo, ls, pwd, touch, etc.</li>
    <li>Supports arguments for commands. EG: ls -a</li>
    <li>Supports operations to connect expressions, such as ||, &&, and ;</li>
        <ul><li>These operations are evaluated from left to right and work just like bash operations.</li></ul>
</ul>

<h1><a name="howToGetTag">How To Install</a></h1>

Download and install the g++ compiler online.
Afterwards, go to your terminal in Linux (alt ctrl t for ubuntu), and enter the following (without the numbers):


<p>
1) git clone http://github.com/jmoon018/rshell.git
<br>
2) cd rshell
<br>
3) git checkout hw0
<br>
4) make
<br>
5) bin/rshell
</p>


<h1><a name="bugsTag">Known Bugs/Limitations</a></h1>
<ol>
    <li>There can't be more than one space at a time. For example: "echo  [insert whitespace]   x" is the same as "echo x"</li>
    <li>The $ prompt won't display properly if the enter button is spammed, but this was reproduced in the bash terminal, too.</li>
    
</ol>

Please contact me at jmoon018@ucr.edu if you have any questions or if you find any unlisted bugs in the code. Thanks.
