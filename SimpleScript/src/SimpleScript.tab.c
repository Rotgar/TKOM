/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "SimpleScript.y" /* yacc.c:337  */

    #include <iostream>
	#include <string>
	#include <memory>
    using namespace std;

	#include "primitive.h"
	#include "identifier.h"
	#include "object.h"
	#include "function.h"
	#include "variable.h"
	#include "exception.h"
	#include "operation_expression.h"
	#include "statement.h"
	#include "assignment.h"
	#include "property.h"
	#include "program.h"

    extern int yylex(void);
    extern int yylineno;
    extern int yyparse();

    extern FILE *yyin;

	int arrayPosition = 0;

    bool errorReported = false;

    void yyerror(const char* s) {
      if(!errorReported) {
         cerr << "ERROR:\t at line " << yylineno << ":\t" << s << endl;
      }
    }

    void yyerror(const char* s, char c) {
      cerr << "ERROR:\tat line " << yylineno << ": " << s << " \"" << c << "\"" << endl;
      errorReported = true;
    }

#line 110 "SimpleScript.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SimpleScript.tab.h".  */
#ifndef YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED
# define YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_T = 258,
    FLOAT_T = 259,
    BOOLEAN_T = 260,
    STRING_T = 261,
    IDENTIFIER = 262,
    ASSIGN = 263,
    COLON = 264,
    SEMICOLON = 265,
    COMMA = 266,
    OPEN_BRACE = 267,
    CLOSE_BRACE = 268,
    IF = 269,
    WHILE = 270,
    VAR = 271,
    FUNCTION_T = 272,
    RETURN = 273,
    PUSH = 274,
    SIZE = 275,
    NO_ELSE = 276,
    ELSE = 277,
    AND = 278,
    OR = 279,
    LESS_THAN = 280,
    LESS_EQUAL_THAN = 281,
    GREATER_THAN = 282,
    GREATER_EQUAL_THAN = 283,
    EQUAL = 284,
    EQUAL_TYPE = 285,
    NOT_EQUAL = 286,
    PLUS = 287,
    MINUS = 288,
    ASTERISK = 289,
    SLASH = 290,
    INC = 291,
    DEC = 292,
    NOT = 293,
    NO_FUNCTION_CALL = 294,
    OPEN_PARENTHESIS = 295,
    CLOSE_PARENTHESIS = 296,
    DOT = 297,
    OPEN_BRACKET = 298,
    CLOSE_BRACKET = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "SimpleScript.y" /* yacc.c:352  */

    int integerVal;
    float floatVal;
    bool booleanVal;
    char* stringVal;
	Identifier* identifierVal;
	StatementsList* statementsListVal;
	Statement* statementVal;
	OperationExpression* operationExpressionVal;
	ParametersList* parametersListVal;
	Object* objectVal;
	PropertyList* propertyListVal;
	Property* propertyVal;
	ArgumentsList* argumentsListyVal;
	OperationExpressionsList* operationExpressionsListVal;
	ObjectLiteral* objectLiteralVal;

#line 216 "SimpleScript.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SIMPLESCRIPT_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

#define YYUNDEFTOK  2
#define YYMAXUTOK   299

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   123,   126,   130,   138,   139,   140,   141,
     142,   143,   146,   149,   154,   158,   162,   168,   172,   176,
     189,   204,   209,   214,   218,   227,   230,   236,   240,   246,
     246,   252,   257,   261,   270,   273,   280,   284,   284,   291,
     292,   296,   300,   304,   308,   312,   316,   320,   324,   328,
     332,   336,   340,   344,   348,   352,   356,   360,   363,   366,
     369,   372,   377,   384,   388,   392,   400,   403,   409,   414,
     422,   425,   436,   444,   453,   457,   461,   469,   472,   475,
     480,   486,   490,   496,   497,   505,   508,   515,   522,   528
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"integer\"", "\"FLOAT\"",
  "\"BOOLEAN\"", "\"STRING\"", "\"IDENTIFIER\"", "\"=\"", "\":\"", "\";\"",
  "\",\"", "\"{\"", "\"}\"", "\"if\"", "\"while\"", "\"var\"",
  "\"function\"", "\"return\"", "\"push\"", "\"size\"", "NO_ELSE", "ELSE",
  "AND", "OR", "LESS_THAN", "LESS_EQUAL_THAN", "GREATER_THAN",
  "GREATER_EQUAL_THAN", "EQUAL", "EQUAL_TYPE", "NOT_EQUAL", "PLUS",
  "MINUS", "ASTERISK", "SLASH", "INC", "DEC", "NOT", "NO_FUNCTION_CALL",
  "OPEN_PARENTHESIS", "CLOSE_PARENTHESIS", "DOT", "OPEN_BRACKET",
  "CLOSE_BRACKET", "$accept", "program", "statements_list", "statement",
  "expression_statement", "assignment_expression", "object_literal",
  "properties_names_and_values", "property_name_and_value", "array", "$@1",
  "array_elements", "array_element", "$@2", "operation_expression",
  "function_call_expression", "arguments_list", "argument",
  "variable_declaration_statement", "variable_declaration_list",
  "variable_declaration", "function_declaration_statement",
  "parameters_list", "function_body", "return_statement",
  "iteration_statement", "conditional_statement", "block", "delimiter",
  "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     259,  -104,  -104,  -104,  -104,  -104,    33,    45,    -3,    -4,
      34,    98,    83,    83,    98,    98,    93,   259,  -104,  -104,
     103,   294,  -104,  -104,  -104,  -104,  -104,  -104,    22,    98,
      98,    87,  -104,   114,  -104,    53,    78,   133,  -104,   294,
    -104,    79,   -12,    99,    99,  -104,   307,  -104,  -104,  -104,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,  -104,   276,    98,    12,    15,   326,   345,
      -3,  -104,     8,   133,  -104,    17,  -104,     9,   138,  -104,
     177,   177,   100,   100,   100,   100,   100,   100,   100,   -12,
     -12,  -104,  -104,   146,  -104,  -104,   111,   141,  -104,   141,
      68,  -104,  -104,   115,   116,   135,   136,   145,   145,  -104,
      75,   151,   165,   175,   126,  -104,    77,    98,  -104,   276,
     150,  -104,  -104,   259,  -104,   170,  -104,   165,  -104,   259,
    -104,   276,   146,  -104,  -104,    24,  -104,  -104,   141,  -104,
    -104,   152,  -104,   183,   145,  -104,   221,  -104,  -104,   141,
    -104,  -104,   276,  -104,  -104,  -104,  -104,  -104,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    40,    41,    42,    43,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     5,     6,
       0,     0,    59,     7,     8,     9,    10,    11,    61,     0,
       0,    89,    70,     0,    69,     0,     0,    74,    85,     0,
      79,    61,    58,    19,    20,    57,     0,     1,     4,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    29,    63,     0,     0,     0,     0,
       0,    67,     0,    74,    76,     0,    78,     0,     0,    39,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    22,    17,    18,     0,    14,    16,    66,
       0,    65,    86,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,    24,    31,     0,    62,    37,
       0,    88,    87,     0,    84,    81,    80,     0,    75,     0,
      73,    29,     0,    21,    36,     0,    33,    29,    34,    35,
      64,     0,    60,     0,     0,    72,     0,    27,    28,    25,
      26,    23,    37,    30,    38,    15,    83,    82,    77,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -103,   -16,  -104,     6,   -62,  -104,    62,   -60,
    -104,  -104,   -77,  -104,    -5,  -104,  -104,    96,  -104,  -104,
     125,   -53,   142,    90,  -104,  -104,  -104,  -101,    67,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,   134,   114,   115,    95,
      96,   135,   136,   137,    21,    22,   100,   101,    23,    33,
      34,    24,    75,   130,    25,    26,    27,   125,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    48,    94,    36,    31,    39,    42,   126,    35,    45,
      46,    98,    43,    44,    32,   102,   102,    28,   105,   102,
     143,   106,    61,    62,    68,    69,   146,   103,   111,   104,
      64,   103,   104,    12,    13,   152,    37,     1,     2,     3,
       4,     5,   141,   157,    38,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   112,    97,
      99,    64,    65,   139,    66,    67,   139,    11,   153,   147,
      35,   148,    14,    29,    15,   159,    32,   154,   150,   117,
       1,     2,     3,     4,     5,    30,   111,    49,    63,    93,
       5,   124,   124,    47,     9,    72,    67,   -71,   -71,   139,
      71,     1,     2,     3,     4,     5,    76,    28,    28,   118,
      11,   138,    99,    38,   138,    14,   127,    15,    73,    65,
     -37,    77,    67,    28,    38,    70,   149,    48,   124,    28,
      48,    11,    59,    60,    61,    62,    14,   132,    15,   133,
      74,    78,    67,    28,    28,   102,    28,   138,     1,     2,
       3,     4,     5,   113,   116,   119,   120,   123,   128,     6,
       7,     8,     9,    10,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   129,    11,   121,
     122,    12,    13,    14,   131,    15,     1,     2,     3,     4,
       5,   142,   144,   155,   151,   109,   156,     6,     7,     8,
       9,    10,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   140,     0,   110,    11,   145,     0,    12,
      13,    14,     0,    15,     1,     2,     3,     4,     5,     0,
       0,     0,     0,     0,   158,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,    12,    13,    14,
       0,    15,     1,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,     0,     1,
       2,     3,     4,     5,     0,     0,     0,     0,    93,     0,
       0,     0,    11,     9,     0,    12,    13,    14,     0,    15,
       0,     0,     0,     0,    38,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    14,     0,    15,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,    79,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,   107,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,   108
};

static const yytype_int16 yycheck[] =
{
       0,    17,    64,     7,     7,    10,    11,   108,     8,    14,
      15,    64,    12,    13,     8,     7,     7,    17,     3,     7,
     123,     6,    34,    35,    29,    30,   129,    19,    11,    20,
       8,    19,    20,    36,    37,    11,    40,     3,     4,     5,
       6,     7,   119,   144,    10,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    41,    64,
      65,     8,    40,   116,    42,    43,   119,    33,    44,   131,
      70,   131,    38,    40,    40,   152,    70,   137,   131,    11,
       3,     4,     5,     6,     7,    40,    11,    20,    21,    12,
       7,   107,   108,     0,    17,    42,    43,    10,    11,   152,
      33,     3,     4,     5,     6,     7,    39,   107,   108,    41,
      33,   116,   117,    10,   119,    38,    41,    40,    40,    40,
      43,    42,    43,   123,    10,    11,   131,   143,   144,   129,
     146,    33,    32,    33,    34,    35,    38,    11,    40,    13,
       7,    42,    43,   143,   144,     7,   146,   152,     3,     4,
       5,     6,     7,     7,    43,    40,    40,    12,     7,    14,
      15,    16,    17,    18,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    12,    33,    44,
      44,    36,    37,    38,     9,    40,     3,     4,     5,     6,
       7,    41,    22,    41,   132,    70,    13,    14,    15,    16,
      17,    18,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   117,    -1,    73,    33,   127,    -1,    36,
      37,    38,    -1,    40,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    36,    37,    38,
      -1,    40,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    33,    17,    -1,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    38,    -1,    40,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    41,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    41,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    14,    15,    16,    17,
      18,    33,    36,    37,    38,    40,    46,    47,    48,    49,
      50,    59,    60,    63,    66,    69,    70,    71,    74,    40,
      40,     7,    50,    64,    65,    74,     7,    40,    10,    59,
      73,    74,    59,    74,    74,    59,    59,     0,    48,    73,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    73,     8,    40,    42,    43,    59,    59,
      11,    73,    42,    40,     7,    67,    73,    42,    42,    41,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    12,    51,    54,    55,    59,    66,    59,
      61,    62,     7,    19,    20,     3,     6,    41,    41,    65,
      67,    11,    41,     7,    52,    53,    43,    11,    41,    40,
      40,    44,    44,    12,    48,    72,    72,    41,     7,    12,
      68,     9,    11,    13,    51,    56,    57,    58,    59,    66,
      62,    57,    41,    47,    22,    68,    47,    51,    54,    59,
      66,    53,    11,    44,    54,    41,    13,    72,    13,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    51,    52,    52,    52,    53,    53,    53,    53,    55,
      54,    56,    56,    56,    57,    57,    57,    58,    57,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    61,    62,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    68,    69,    69,
      70,    71,    71,    72,    72,    73,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     6,     3,     3,     3,     2,
       2,     3,     0,     3,     1,     3,     3,     3,     3,     0,
       4,     0,     3,     1,     1,     1,     1,     0,     2,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       5,     1,     4,     0,     3,     1,     1,     3,     3,     1,
       1,     1,     6,     5,     0,     3,     1,     3,     3,     2,
       5,     5,     7,     3,     1,     1,     3,     4,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 120 "SimpleScript.y" /* yacc.c:1652  */
    {
										Program(std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal))).evaluate();
									}
#line 1471 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 126 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-1].statementsListVal)->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));
										(yyval.statementsListVal) = (yyvsp[-1].statementsListVal);
									}
#line 1480 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 130 "SimpleScript.y" /* yacc.c:1652  */
    {
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));

										(yyval.statementsListVal) = stmtsList;
									}
#line 1491 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 146 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new ExpressionStatement(std::shared_ptr<OperationExpression>((yyvsp[-1].operationExpressionVal)));
									}
#line 1499 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 149 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new ExpressionStatement(std::shared_ptr<OperationExpression>((yyvsp[-1].operationExpressionVal)));
									}
#line 1507 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 154 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)),
												std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1516 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 158 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new ArrayPushExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[-5].identifierVal)),
												std::shared_ptr<Property>((yyvsp[-1].propertyVal)));
									}
#line 1525 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 162 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.operationExpressionVal) = new FunctionAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)), funct);
									}
#line 1536 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 168 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new ObjectLiteralAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)),
											std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1545 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 172 "SimpleScript.y" /* yacc.c:1652  */
    {
									(yyval.operationExpressionVal) = new ObjectLiteralAssignment(std::shared_ptr<Identifier>((yyvsp[-2].identifierVal)),
											std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
                  					}
#line 1554 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 176 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive onePrimitive = Primitive(1);
										Variable one = Variable(onePrimitive);
										ConstantExpression oneConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

										OperationExpression* expression = new Addition(
											std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)))),
											std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)));

										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)),
												std::shared_ptr<OperationExpression>(expression));
									}
#line 1572 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 189 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive onePrimitive = Primitive(1);
										Variable one = Variable(onePrimitive);
										ConstantExpression oneConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(one)));

										OperationExpression* expression = new Subtraction(
											std::shared_ptr<OperationExpression>(new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)))),
											std::shared_ptr<OperationExpression>(new ConstantExpression(oneConstantExpression)));

										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)),
												std::shared_ptr<OperationExpression>(expression));
									}
#line 1590 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 204 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.objectLiteralVal) = new ObjectLiteral(shared_ptr<PropertyList>((yyvsp[-1].propertyListVal)));
									}
#line 1598 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 209 "SimpleScript.y" /* yacc.c:1652  */
    {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(false);
										(yyval.propertyListVal) = propertyList;
									}
#line 1608 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 214 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].propertyListVal)->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));
										(yyval.propertyListVal) = (yyvsp[-2].propertyListVal);
									}
#line 1617 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 218 "SimpleScript.y" /* yacc.c:1652  */
    {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(false);
										propertyList->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));

										(yyval.propertyListVal) = propertyList;
									}
#line 1629 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 227 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1637 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 230 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<Function>(new Function(funct)));
									}
#line 1648 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 236 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1656 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 240 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.propertyVal) = new Property((yyvsp[-2].stringVal), std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1664 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 246 "SimpleScript.y" /* yacc.c:1652  */
    { Property::setElementCounter(0); }
#line 1670 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 247 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.objectLiteralVal) = new ObjectLiteral(shared_ptr<PropertyList>((yyvsp[-1].propertyListVal)));
									}
#line 1678 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 252 "SimpleScript.y" /* yacc.c:1652  */
    {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(true);
										(yyval.propertyListVal) = propertyList;
									}
#line 1688 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 257 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].propertyListVal)->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));
										(yyval.propertyListVal) = (yyvsp[-2].propertyListVal);
									}
#line 1697 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 261 "SimpleScript.y" /* yacc.c:1652  */
    {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(true);
										propertyList->add(std::shared_ptr<Property>((yyvsp[0].propertyVal)));

										(yyval.propertyListVal) = propertyList;
									}
#line 1709 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 270 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.propertyVal) = new Property(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1717 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 273 "SimpleScript.y" /* yacc.c:1652  */
    {
										FunctionDeclarationStatement* fdstmtPtr = 
											dynamic_cast<FunctionDeclarationStatement*> ((yyvsp[0].statementVal));
										Function funct = fdstmtPtr->getFunction();

										(yyval.propertyVal) = new Property(std::shared_ptr<Function>(new Function(funct)));
                                	}
#line 1729 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 280 "SimpleScript.y" /* yacc.c:1652  */
    {
                  						(yyval.propertyVal) = new Property(std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
									}
#line 1737 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 284 "SimpleScript.y" /* yacc.c:1652  */
    { arrayPosition = Property::getElementCounter(); }
#line 1743 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 285 "SimpleScript.y" /* yacc.c:1652  */
    {
										Property::setElementCounter(arrayPosition);
                  						(yyval.propertyVal) = new Property(std::shared_ptr<ObjectLiteral>((yyvsp[0].objectLiteralVal)));
                                	}
#line 1752 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 291 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[-1].operationExpressionVal); }
#line 1758 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 292 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive primitive = Primitive((yyvsp[0].integerVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive)));
									}
#line 1767 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 296 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive primitive = Primitive((yyvsp[0].floatVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive)));
									}
#line 1776 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 300 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive primitive = Primitive((yyvsp[0].booleanVal));
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive)));
									}
#line 1785 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 304 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive primitive = Primitive(std::string((yyvsp[0].stringVal)), true);
										(yyval.operationExpressionVal) = new ConstantExpression(std::shared_ptr<Variable>(new Variable(primitive)));
									}
#line 1794 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 308 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new LogicalAnd(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1803 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 312 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new LogicalOr(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1812 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 316 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new LessThan(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1821 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 320 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new LessThanOrEqualTo(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1830 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 324 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new GreaterThan(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1839 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 328 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new GreaterThanOrEqualTo(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1848 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 332 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new Equals(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1857 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 336 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new EqualsType(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1866 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 340 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new NotEquals(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1875 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 344 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new Addition(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1884 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 348 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new Subtraction(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1893 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 352 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new Multiplication(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1902 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 356 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new Division(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
											std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1911 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 360 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new LogicalNot(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1919 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 363 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new Negation(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
									}
#line 1927 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 366 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); 
									}
#line 1935 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 369 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new ArraySizeExpression(std::shared_ptr<Identifier>((yyvsp[-4].identifierVal)));
									}
#line 1943 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 372 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new IdentifierExpression(std::shared_ptr<Identifier>((yyvsp[0].identifierVal)));
									}
#line 1951 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 377 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.operationExpressionVal) = new FunctionCallExpression(
											std::shared_ptr<Identifier>((yyvsp[-3].identifierVal)),
											std::shared_ptr<ArgumentsList>((yyvsp[-1].argumentsListyVal)));
									}
#line 1961 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 384 "SimpleScript.y" /* yacc.c:1652  */
    {
										ArgumentsList* argsList = new ArgumentsList();
										(yyval.argumentsListyVal) = argsList;
									}
#line 1970 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 388 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].argumentsListyVal)->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));
										(yyval.argumentsListyVal) = (yyvsp[-2].argumentsListyVal);
									}
#line 1979 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 392 "SimpleScript.y" /* yacc.c:1652  */
    {
										ArgumentsList* argsList = new ArgumentsList();
										argsList->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.argumentsListyVal) = argsList;
									}
#line 1990 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 400 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal); }
#line 1996 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 403 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new VariableDeclarationStatement(
											std::shared_ptr<OperationExpressionsList>((yyvsp[-1].operationExpressionsListVal)));
									}
#line 2005 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 409 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].operationExpressionsListVal)->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.operationExpressionsListVal) = (yyvsp[-2].operationExpressionsListVal);
									}
#line 2015 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 414 "SimpleScript.y" /* yacc.c:1652  */
    {
										OperationExpressionsList* list = new OperationExpressionsList();
										list->add(std::shared_ptr<OperationExpression>((yyvsp[0].operationExpressionVal)));

										(yyval.operationExpressionsListVal) = list;
									}
#line 2026 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 422 "SimpleScript.y" /* yacc.c:1652  */
    { 
										(yyval.operationExpressionVal) = (yyvsp[0].operationExpressionVal);
									}
#line 2034 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 425 "SimpleScript.y" /* yacc.c:1652  */
    {
										Primitive zeroPrimitive = Primitive(0);
										Variable zero = Variable(zeroPrimitive);
										ConstantExpression zeroConstantExpression =
											ConstantExpression(std::shared_ptr<Variable>(new Variable(zero)));

										(yyval.operationExpressionVal) = new OperationExpressionAssignment(std::shared_ptr<Identifier>(new Identifier((yyvsp[0].stringVal))),
												std::shared_ptr<OperationExpression>(new ConstantExpression(zeroConstantExpression)));
									}
#line 2048 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 436 "SimpleScript.y" /* yacc.c:1652  */
    {
										Function* functionPtr = new Function(std::shared_ptr<ParametersList>((yyvsp[-2].parametersListVal)),
											std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));

										(yyval.statementVal) = new FunctionDeclarationStatement(std::shared_ptr<Function>(functionPtr),
											std::shared_ptr<Identifier>(new Identifier((yyvsp[-4].stringVal))));

									}
#line 2061 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 444 "SimpleScript.y" /* yacc.c:1652  */
    {
										Function* functionPtr = new Function(std::shared_ptr<ParametersList>((yyvsp[-2].parametersListVal)),
											std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));

										(yyval.statementVal) = new FunctionDeclarationStatement(std::shared_ptr<Function>(functionPtr));

									}
#line 2073 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 453 "SimpleScript.y" /* yacc.c:1652  */
    {
										ParametersList* paramsList = new ParametersList();
										(yyval.parametersListVal) = paramsList;
									}
#line 2082 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 457 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyvsp[-2].parametersListVal)->add((yyvsp[0].stringVal));
										(yyval.parametersListVal) = (yyvsp[-2].parametersListVal);
									}
#line 2091 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 461 "SimpleScript.y" /* yacc.c:1652  */
    {
										ParametersList* paramsList = new ParametersList();
										paramsList->add((yyvsp[0].stringVal));

										(yyval.parametersListVal) = paramsList;
									}
#line 2102 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 469 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.statementsListVal) = (yyvsp[-1].statementsListVal); }
#line 2108 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 472 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new ReturnStatement(std::shared_ptr<OperationExpression>((yyvsp[-1].operationExpressionVal)));
									}
#line 2116 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 475 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new ReturnStatement();
								}
#line 2124 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 480 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new IterationStatement(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
												std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 2133 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 486 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new ConditionalStatement(std::shared_ptr<OperationExpression>((yyvsp[-2].operationExpressionVal)),
												std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 2142 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 490 "SimpleScript.y" /* yacc.c:1652  */
    {
										(yyval.statementVal) = new ConditionalStatement(std::shared_ptr<OperationExpression>((yyvsp[-4].operationExpressionVal)),
												std::shared_ptr<StatementsList>((yyvsp[-2].statementsListVal)), std::shared_ptr<StatementsList>((yyvsp[0].statementsListVal)));
									}
#line 2151 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 496 "SimpleScript.y" /* yacc.c:1652  */
    { (yyval.statementsListVal) = (yyvsp[-1].statementsListVal); }
#line 2157 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 497 "SimpleScript.y" /* yacc.c:1652  */
    {
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(std::shared_ptr<Statement>((yyvsp[0].statementVal)));

										(yyval.statementsListVal) = stmtsList;
									}
#line 2168 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 508 "SimpleScript.y" /* yacc.c:1652  */
    {
										Identifier* id = new Identifier(*((yyvsp[-2].identifierVal)), (yyvsp[0].stringVal));
										(yyval.identifierVal) = id;

										delete (yyvsp[-2].identifierVal);
										delete [] (yyvsp[0].stringVal);
									}
#line 2180 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 515 "SimpleScript.y" /* yacc.c:1652  */
    {
										Identifier* id = new Identifier(*((yyvsp[-3].identifierVal)), (yyvsp[-1].stringVal), true);
										(yyval.identifierVal) = id;

										delete (yyvsp[-3].identifierVal);
										delete [] (yyvsp[-1].stringVal);
									}
#line 2192 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 522 "SimpleScript.y" /* yacc.c:1652  */
    {
                    					Identifier* id = new Identifier(*((yyvsp[-3].identifierVal)), (yyvsp[-1].integerVal));
        								(yyval.identifierVal) = id;

										delete (yyvsp[-3].identifierVal);
                  					}
#line 2203 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 528 "SimpleScript.y" /* yacc.c:1652  */
    {
										Identifier* id = new Identifier((yyvsp[0].stringVal));
										(yyval.identifierVal) = id;

										delete [] (yyvsp[0].stringVal);
									}
#line 2214 "SimpleScript.tab.c" /* yacc.c:1652  */
    break;


#line 2218 "SimpleScript.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 535 "SimpleScript.y" /* yacc.c:1918  */

