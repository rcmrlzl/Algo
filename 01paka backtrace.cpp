{\rtf1\ansi\ansicpg936\cocoartf1504\cocoasubrtf810
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset134 PingFangSC-Regular;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red196\green26\blue22;\red170\green13\blue145;
\red0\green0\blue0;\red92\green38\blue153;\red0\green116\blue0;\red28\green0\blue207;\red63\green110\blue116;
\red38\green71\blue75;\red46\green13\blue110;}
{\*\expandedcolortbl;;\csgenericrgb\c39100\c22000\c12500;\csgenericrgb\c77000\c10200\c8600;\csgenericrgb\c66500\c5200\c56900;
\csgenericrgb\c0\c0\c0;\csgenericrgb\c35900\c14900\c60100;\csgenericrgb\c0\c45600\c0;\csgenericrgb\c11000\c0\c81000;\csgenericrgb\c24700\c43100\c45600;
\csgenericrgb\c14900\c27800\c29400;\csgenericrgb\c18100\c5200\c43100;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab543
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \CocoaLigature0 #include\cf3 <iostream>\cf2 \
\cf4 using\cf5  \cf4 namespace\cf5  \cf6 std\cf5 ;\
\cf4 int\cf5  n,c,bestp;\cf7 //
\f1 \'ce\'ef\'c6\'b7\'b5\'c4\'b8\'f6\'ca\'fd\'a3\'ac\'b1\'b3\'b0\'fc\'b5\'c4\'c8\'dd\'c1\'bf\'a3\'ac\'d7\'ee\'b4\'f3\'bc\'db\'d6\'b5
\f0 \cf5 \
\cf4 int\cf5  p[\cf8 10000\cf5 ],w[\cf8 10000\cf5 ],x[\cf8 10000\cf5 ],bestx[\cf8 10000\cf5 ];\cf7 //
\f1 \'ce\'ef\'c6\'b7\'b5\'c4\'bc\'db\'d6\'b5\'a3\'ac\'ce\'ef\'c6\'b7\'b5\'c4\'d6\'d8\'c1\'bf\'a3\'ac
\f0 x[i]
\f1 \'d4\'dd\'b4\'e6\'ce\'ef\'c6\'b7\'b5\'c4\'d1\'a1\'d6\'d0\'c7\'e9\'bf\'f6
\f0 ,
\f1 \'ce\'ef\'c6\'b7\'b5\'c4\'d1\'a1\'d6\'d0\'c7\'e9\'bf\'f6
\f0 \cf5 \
\
\cf4 double\cf5  Backtrack(\cf4 int\cf5  i,\cf4 int\cf5  cp,\cf4 int\cf5  cw)\
\{ \cf7 //cw
\f1 \'b5\'b1\'c7\'b0\'b0\'fc\'c4\'da\'ce\'ef\'c6\'b7\'d6\'d8\'c1\'bf\'a3\'ac
\f0 cp
\f1 \'b5\'b1\'c7\'b0\'b0\'fc\'c4\'da\'ce\'ef\'c6\'b7\'bc\'db\'d6\'b5
\f0 \cf5 \
    \cf4 int\cf5  j;\
    \cf4 double\cf5  sum = \cf8 0\cf5 ;\
    \cf4 if\cf5 (i>\cf9 n\cf5 )\cf7 //
\f1 \'bb\'d8\'cb\'dd\'bd\'e1\'ca\'f8
\f0 \cf5 \
    \{\
        \cf4 if\cf5 (cp>\cf9 bestp\cf5 )\
        \{\
            \cf9 bestp\cf5 =cp;\
            \cf4 for\cf5 (i=\cf8 0\cf5 ;i<=\cf9 n\cf5 ;i++) \cf9 bestx\cf5 [i]=\cf9 x\cf5 [i];\
        \}\
    \}\
    \cf4 else\cf5 \
        \cf4 for\cf5 (j=\cf8 0\cf5 ;j<=\cf8 1\cf5 ;j++)\
        \{\
            \cf9 x\cf5 [i]=j;\
            \cf4 if\cf5 (cw+\cf9 x\cf5 [i]*\cf9 w\cf5 [i]<=\cf9 c\cf5 )\
            \{\
                cw+=\cf9 w\cf5 [i]*\cf9 x\cf5 [i];\
                cp+=\cf9 p\cf5 [i]*\cf9 x\cf5 [i];\
                \cf10 Backtrack\cf5 (i+\cf8 1\cf5 ,cp,cw);\
                cw-=\cf9 w\cf5 [i]*\cf9 x\cf5 [i];\
                cp-=\cf9 p\cf5 [i]*\cf9 x\cf5 [i];\
            \}\
        \}\
    \cf4 for\cf5 (\cf4 int\cf5  i=\cf8 0\cf5 ;i<\cf9 n\cf5 ;i++)\{\
        \cf4 if\cf5 (\cf9 bestx\cf5 [i] == \cf8 1\cf5 )\{\
            sum+=\cf9 p\cf5 [i];\
        \}\
    \}\
    \cf4 return\cf5  sum;\
\}\
\
\cf4 int\cf5  main()\
\{\
    \cf4 int\cf5  i;\
    \cf9 bestp\cf5 =\cf8 0\cf5 ;\
    \cf6 cout\cf5 <<\cf3 "
\f1 \'c7\'eb\'ca\'e4\'c8\'eb\'d7\'ee\'b4\'f3\'b1\'b3\'b0\'fc\'c8\'dd\'c1\'bf
\f0 :"\cf5 <<\cf11 endl\cf5 ;\
    \cf6 cin\cf5 >>\cf9 c\cf5 ;\
    \cf6 cout\cf5 <<\cf3 "
\f1 \'c7\'eb\'ca\'e4\'c8\'eb\'ce\'ef\'c6\'b7\'b8\'f6\'ca\'fd
\f0 :"\cf5 <<\cf11 endl\cf5 ;\
    \cf6 cin\cf5 >>\cf9 n\cf5 ;\
    \cf6 cout\cf5 <<\cf3 "
\f1 \'c7\'eb\'d2\'c0\'b4\'ce\'ca\'e4\'c8\'eb\'ce\'ef\'c6\'b7\'d6\'d8\'c1\'bf
\f0 :"\cf5 <<\cf11 endl\cf5 ;\
    \cf4 for\cf5 (i=\cf8 1\cf5 ;i<=\cf9 n\cf5 ;i++)\
        \cf6 cin\cf5 >>\cf9 w\cf5 [i];\
    \cf6 cout\cf5 <<\cf3 "
\f1 \'c7\'eb\'ca\'e4\'c8\'eb\'ce\'ef\'c6\'b7\'b5\'c4\'bc\'db\'d6\'b5
\f0 :"\cf5 <<\cf11 endl\cf5 ;\
    \cf4 for\cf5 (i=\cf8 1\cf5 ;i<=\cf9 n\cf5 ;i++)\
        \cf6 cin\cf5 >>\cf9 p\cf5 [i];\
    \cf4 double\cf5  sum = \cf10 Backtrack\cf5 (\cf8 1\cf5 ,\cf8 0\cf5 ,\cf8 0\cf5 );\
    \cf6 cout\cf5 <<\cf3 "
\f1 \'b1\'bb\'d1\'a1\'d6\'d0\'b5\'c4\'ce\'ef\'c6\'b7\'d2\'c0\'b4\'ce\'ca\'c7
\f0 (0
\f1 \'b1\'ed\'ca\'be\'ce\'b4\'d1\'a1\'d6\'d0\'a3\'ac
\f0 1
\f1 \'b1\'ed\'ca\'be\'d1\'a1\'d6\'d0
\f0 )"\cf5 <<\cf11 endl\cf5 ;;\
    \cf4 for\cf5 (i=\cf8 1\cf5 ;i<=\cf9 n\cf5 ;i++)\
        \cf6 cout\cf5 <<\cf9 bestx\cf5 [i];\
    \cf6 cout\cf5 <<\cf11 endl\cf5 ;\
    \cf6 cout\cf5 <<\cf3 "
\f1 \'d7\'ee\'b4\'f3\'bc\'db\'d6\'b5\'ce\'aa
\f0 :"\cf5 <<sum<<\cf11 endl\cf5 ;\
    \cf4 return\cf5  \cf8 0\cf5 ;\
\}\
\
\
\
\
\
\
\
\
}