## Let's build a simple lexer in C

If you want to compile a C program, interpret a Lisp program, or transform some Markdown into HTML, you need to build a compiler, which means you need to build a parser, which means you need to build a lexer.

A lexer turns a stream of characters into a stream of tokens.  A parser turns that stream of tokens into a [parse tree](https://en.wikipedia.org/wiki/Parse_tree).

Let's start off by building a lexer which tokenizes a very simple [XML](https://en.wikipedia.org/wiki/XML)-like grammar:
- A "start tag" is a name inside of angle brackets, e.g. "<div>"
- An "end tag" has a slash after the opening bracket, e.g. "</div>"
- An "empty-element tag" has a slash before the closing bracket, e.g. "<img/>"
