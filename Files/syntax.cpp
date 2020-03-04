#include "syntax.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(QColor(121,176,225));
    QStringList keywordPatternsblue;
    QStringList keywordPatternspurple;
    keywordPatternsblue << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                    << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                    << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                    << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\breturn\\b"
                    << "\\busing\\b";

    keywordPatternspurple << "\\b#include\\b" << "\\b#pragme\\b" << "\\b#line\\b"
                          << "\\b#if\\b" << "\\b#ifdef\\b" << "\\b#define\\b";

    foreach (const QString &pattern, keywordPatternsblue) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    classFormat.setForeground(Qt::lightGray);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::lightGray);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("#include");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("#pragma");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("#line");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("if");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("else");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("switch");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("break");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("#if");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("#ifdef");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(118,68,170));
    rule.pattern = QRegExp("#define");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(45,193,64));
    rule.pattern = QRegExp("cout");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(45,193,64));
    rule.pattern = QRegExp("string");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(45,193,64));
    rule.pattern = QRegExp("endl");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor(45,193,64));
    rule.pattern = QRegExp("std");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::lightGray);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::lightGray);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    } setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
