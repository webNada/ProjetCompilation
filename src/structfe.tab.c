/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "structfe.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/types_and_symbols.h"
#include "src/semantic_actions.h"



int yylex(void);   // Déclaration de yylex pour garantir sa visibilité
extern int yylineno;  

int yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    return 0;
}

#line 89 "structfe.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "structfe.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_LE_OP = 8,                      /* LE_OP  */
  YYSYMBOL_GE_OP = 9,                      /* GE_OP  */
  YYSYMBOL_EQ_OP = 10,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 11,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 12,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 13,                     /* OR_OP  */
  YYSYMBOL_EXTERN = 14,                    /* EXTERN  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_THEN = 22,                      /* THEN  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '.'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '&'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_primary_expression = 40,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 41,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 42,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 43,          /* unary_expression  */
  YYSYMBOL_unary_operator = 44,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 45, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 46,       /* additive_expression  */
  YYSYMBOL_shift_expression = 47,          /* shift_expression  */
  YYSYMBOL_relational_expression = 48,     /* relational_expression  */
  YYSYMBOL_equality_expression = 49,       /* equality_expression  */
  YYSYMBOL_logical_and_expression = 50,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 51,     /* logical_or_expression  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 54,    /* declaration_specifiers  */
  YYSYMBOL_type_specifier = 55,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 56,          /* struct_specifier  */
  YYSYMBOL_struct_declaration_list = 57,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 58,        /* struct_declaration  */
  YYSYMBOL_declarator = 59,                /* declarator  */
  YYSYMBOL_direct_declarator = 60,         /* direct_declarator  */
  YYSYMBOL_parameter_list = 61,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 62,     /* parameter_declaration  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_compound_statement = 64,        /* compound_statement  */
  YYSYMBOL_declaration_list = 65,          /* declaration_list  */
  YYSYMBOL_statement_list = 66,            /* statement_list  */
  YYSYMBOL_expression_statement = 67,      /* expression_statement  */
  YYSYMBOL_selection_statement = 68,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 69,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 70,            /* jump_statement  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_external_declaration = 72,      /* external_declaration  */
  YYSYMBOL_function_definition = 73        /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,     2,
      30,    31,    26,    24,    33,    25,    32,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      28,    35,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    97,   119,   125,   129,   142,   149,   150,
     154,   158,   165,   168,   176,   189,   213,   214,   215,   219,
     222,   241,   265,   268,   287,   309,   313,   332,   353,   356,
     375,   394,   413,   434,   438,   457,   480,   484,   508,   512,
     535,   538,   560,   584,   595,   603,   614,   636,   658,   664,
     678,   687,   711,   714,   727,   751,   774,   786,   816,   820,
     831,   845,   849,   858,   876,   879,   882,   885,   888,   894,
     898,   902,   906,   915,   918,   925,   929,   938,   942,   952,
     968,   989,  1004,  1028,  1032,  1044,  1049,  1057,  1061,  1069
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "INTEGER", "SIZEOF", "PTR_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "EXTERN", "INT", "VOID", "STRUCT", "IF",
  "WHILE", "FOR", "RETURN", "THEN", "ELSE", "'+'", "'-'", "'*'", "'/'",
  "'<'", "'>'", "'('", "')'", "'.'", "','", "'&'", "'='", "';'", "'{'",
  "'}'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "expression", "declaration",
  "declaration_specifiers", "type_specifier", "struct_specifier",
  "struct_declaration_list", "struct_declaration", "declarator",
  "direct_declarator", "parameter_list", "parameter_declaration",
  "statement", "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,   125,   -74,   -74,    12,   -74,    22,   -74,   -27,   225,
     -74,   -74,   -74,   -74,   -24,   125,   -74,    20,    22,    54,
      -4,   -74,   -74,   -74,   125,    22,    77,   -74,    -4,    -2,
     -74,    93,   -74,     2,   200,    -5,   -74,   -74,   -74,   -74,
     -74,   243,    26,    42,    48,   218,   -74,   -74,   272,   -74,
     -74,   -74,   -74,    21,    60,   272,    15,    92,   117,   254,
     140,   108,   115,    62,   -74,    22,   -74,   -74,   118,   143,
     -74,   -74,   -74,   -74,   -74,    22,   -21,   -74,   -74,   -74,
     255,   -74,   272,   272,   230,   -74,    69,   114,   150,    51,
     164,   272,   -74,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   -74,   134,   -74,
     -74,   168,   -74,   -74,   -74,   -74,    86,   147,   159,   160,
     230,   -74,   -74,   -74,   -74,    -9,   -74,   -74,   -74,   -74,
     -74,   -74,    15,    15,    92,    92,   157,   157,   157,   157,
     254,   254,   140,   108,   -74,   -74,   -74,   193,   193,   272,
     -74,   272,   169,   -74,   170,   -74,   193,   193,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    47,    46,     0,    88,     0,    45,    48,     0,
      85,    87,    44,    48,    51,     0,    57,     0,     0,     0,
      56,    43,     1,    86,     0,     0,     0,    52,    55,     0,
      42,     0,    89,     0,     0,     0,    50,    53,    58,     2,
       3,     0,     0,     0,     0,     0,    18,    17,     0,    16,
      77,    69,     5,    12,    19,     0,    22,    25,    28,    33,
      36,    38,    40,     0,    73,     0,    75,    64,     0,     0,
      65,    66,    67,    68,    60,     0,     0,    61,    49,    54,
       0,    14,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    71,
      74,     0,    70,    76,    63,    59,     0,     0,     0,     0,
       0,    84,     4,     9,     6,     0,    10,     8,    41,    20,
      21,    19,    23,    24,    26,    27,    31,    32,    29,    30,
      34,    35,    37,    39,    72,    62,    15,     0,     0,     0,
       7,     0,    79,    81,     0,    11,     0,     0,    80,    82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -35,   -74,    80,    85,    58,    81,
      90,    94,   -74,   -45,   -23,   -29,     6,     5,   179,    49,
       9,   190,   -74,   104,   -68,   189,   -74,   141,   -73,   -74,
     -74,   -74,   -74,   201,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    52,    53,   125,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     5,     6,     7,    13,    26,    27,
      19,    20,    76,    77,    66,    67,    68,    69,    70,    71,
      72,    73,     9,    10,    11
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   113,    65,    87,    75,     8,    81,    12,    64,    21,
     115,   120,   116,    24,     8,    14,     1,     2,     3,     4,
      92,    25,   150,    16,   151,    16,    33,    29,    88,    38,
      25,    79,    25,    74,    35,    87,     8,   118,   119,    65,
      25,    93,    94,   113,   126,   110,   128,   149,    17,    15,
      18,    89,    18,    90,    39,    40,    82,    41,   129,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,    83,     8,   108,    37,    46,    47,    84,   152,
     153,    48,   124,    37,   114,    49,   117,    75,   158,   159,
      30,    31,     2,     3,     4,    91,    39,    40,   107,    41,
       1,     2,     3,     4,   154,   121,   155,     1,     2,     3,
       4,    42,    43,    44,    45,    36,    95,    96,    46,    47,
     105,    39,    40,    48,    41,    97,    98,    49,   106,    50,
      31,    51,     1,     2,     3,     4,    42,    43,    44,    45,
       2,     3,     4,    46,    47,   122,    39,    40,    48,    41,
     103,   104,    49,   123,    50,    31,   109,   136,   137,   138,
     139,    42,    43,    44,    45,    -1,    -1,   127,    46,    47,
      30,    39,    40,    48,    41,   132,   133,    49,   146,    50,
      31,   112,   134,   135,   140,   141,    42,    43,    44,    45,
     147,   148,   156,    46,    47,   142,    39,    40,    48,    41,
     143,   157,    49,    34,    50,    31,   144,    28,    32,   111,
      23,    42,    43,    44,    45,     2,     3,     4,    46,    47,
     145,    39,    40,    48,    41,    22,     0,    49,     0,    50,
      31,     0,     0,    39,    40,     0,    41,     0,    78,     1,
       2,     3,     4,    46,    47,     0,    39,    40,    48,    41,
       0,     0,    49,     0,    85,    46,    47,     0,    39,    40,
      48,    41,    99,   100,    49,     0,    50,     0,    46,    47,
       2,     3,     4,    80,     0,    39,    40,    49,    41,     0,
      46,    47,   101,   102,     0,    48,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     0,
       0,     0,    48,     0,     0,     0,    49
};

static const yytype_int16 yycheck[] =
{
      45,    69,    31,    48,    33,     0,    41,     1,    31,    36,
      31,    84,    33,    37,     9,     3,    14,    15,    16,    17,
      55,    15,    31,     3,    33,     3,    30,    18,     7,    31,
      24,    36,    26,    31,    25,    80,    31,    82,    83,    68,
      34,    26,    27,   111,    89,    68,    91,   120,    26,    37,
      30,    30,    30,    32,     3,     4,    30,     6,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    30,    68,    65,    26,    25,    26,    30,   147,
     148,    30,    31,    34,    75,    34,    80,   116,   156,   157,
      36,    37,    15,    16,    17,    35,     3,     4,    36,     6,
      14,    15,    16,    17,   149,    36,   151,    14,    15,    16,
      17,    18,    19,    20,    21,    38,    24,    25,    25,    26,
      12,     3,     4,    30,     6,     8,     9,    34,    13,    36,
      37,    38,    14,    15,    16,    17,    18,    19,    20,    21,
      15,    16,    17,    25,    26,    31,     3,     4,    30,     6,
      10,    11,    34,     3,    36,    37,    38,    99,   100,   101,
     102,    18,    19,    20,    21,     8,     9,     3,    25,    26,
      36,     3,     4,    30,     6,    95,    96,    34,    31,    36,
      37,    38,    97,    98,   103,   104,    18,    19,    20,    21,
      31,    31,    23,    25,    26,   105,     3,     4,    30,     6,
     106,    31,    34,    24,    36,    37,    38,    17,    19,    68,
       9,    18,    19,    20,    21,    15,    16,    17,    25,    26,
     116,     3,     4,    30,     6,     0,    -1,    34,    -1,    36,
      37,    -1,    -1,     3,     4,    -1,     6,    -1,    38,    14,
      15,    16,    17,    25,    26,    -1,     3,     4,    30,     6,
      -1,    -1,    34,    -1,    36,    25,    26,    -1,     3,     4,
      30,     6,     8,     9,    34,    -1,    36,    -1,    25,    26,
      15,    16,    17,    30,    -1,     3,     4,    34,     6,    -1,
      25,    26,    28,    29,    -1,    30,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    16,    17,    53,    54,    55,    56,    71,
      72,    73,    55,    56,     3,    37,     3,    26,    30,    59,
      60,    36,     0,    72,    37,    55,    57,    58,    60,    59,
      36,    37,    64,    30,    57,    59,    38,    58,    31,     3,
       4,     6,    18,    19,    20,    21,    25,    26,    30,    34,
      36,    38,    40,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    63,    64,    65,    66,
      67,    68,    69,    70,    31,    54,    61,    62,    38,    36,
      30,    43,    30,    30,    30,    36,    52,    52,     7,    30,
      32,    35,    43,    26,    27,    24,    25,     8,     9,     8,
       9,    28,    29,    10,    11,    12,    13,    36,    59,    38,
      53,    66,    38,    63,    59,    31,    33,    55,    52,    52,
      67,    36,    31,     3,    31,    42,    52,     3,    52,    43,
      43,    43,    45,    45,    46,    46,    47,    47,    47,    47,
      48,    48,    49,    50,    38,    62,    31,    31,    31,    67,
      31,    33,    63,    63,    52,    52,    23,    31,    63,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      42,    42,    43,    43,    43,    43,    44,    44,    44,    45,
      45,    45,    46,    46,    46,    47,    47,    47,    48,    48,
      48,    48,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    56,
      56,    56,    57,    57,    58,    59,    59,    60,    60,    60,
      60,    61,    61,    62,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       1,     3,     1,     2,     2,     4,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     3,     2,     2,     1,     1,     1,     1,     5,
       4,     2,     1,     2,     3,     2,     1,     1,     3,     4,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     2,
       3,     3,     4,     1,     2,     1,     2,     1,     2,     5,
       7,     5,     7,     2,     3,     1,     2,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 78 "structfe.y"
                 {
        printf("Debug: IDENTIFIER %s at line %d\n", (yyvsp[0].string), yylineno);
        (yyval.exprAttributes) = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if ((yyval.exprAttributes) == NULL) {
            yyerror("Allocation failure");
            YYABORT;
        }

        (yyval.exprAttributes)->symbol = checkIdentifier((yyvsp[0].string));
        if ((yyval.exprAttributes)->symbol == NULL) {
            yyerror("Identifiant non déclaré.");
            (yyval.exprAttributes)->code = init_code(1, "");
            (yyval.exprAttributes)->type = NULL;
        } else {
            printf("Debug: Identifier %s found at line %d\n", (yyval.exprAttributes)->symbol->identifier, yylineno);
            (yyval.exprAttributes)->code = init_code(1, (yyval.exprAttributes)->symbol->identifier);
            (yyval.exprAttributes)->type = (yyval.exprAttributes)->symbol->type;
        }
    }
#line 1575 "structfe.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 97 "structfe.y"
               {
        printf("Debug: CONSTANT %s at line %d\n", (yyvsp[0].string), yylineno);

        (yyval.exprAttributes) = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if ((yyval.exprAttributes) == NULL) {
            yyerror("Allocation failure");
            YYABORT;
        }

        (yyval.exprAttributes)->symbol = (SymbolEntry*) malloc(sizeof(SymbolEntry));
        if ((yyval.exprAttributes)->symbol == NULL) {
            yyerror("Allocation failure");
            free((yyval.exprAttributes));
            YYABORT;
        }

        (yyval.exprAttributes)->symbol->identifier = strdup((yyvsp[0].string));
        (yyval.exprAttributes)->symbol->type = createType(TYPE_INT);
        (yyval.exprAttributes)->symbol->isConstant = 1;
        (yyval.exprAttributes)->code = init_code(1, (yyvsp[0].string));
        (yyval.exprAttributes)->type = (yyval.exprAttributes)->symbol->type;
    }
#line 1602 "structfe.tab.c"
    break;

  case 4: /* primary_expression: '(' expression ')'  */
#line 119 "structfe.y"
                         {
        (yyval.exprAttributes) = (yyvsp[-1].exprAttributes);
    }
#line 1610 "structfe.tab.c"
    break;

  case 5: /* postfix_expression: primary_expression  */
#line 125 "structfe.y"
                         {
        printf("Debug: Postfix expression - primary_expression\n");
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 1619 "structfe.tab.c"
    break;

  case 6: /* postfix_expression: postfix_expression '(' ')'  */
#line 129 "structfe.y"
                                 {
        printf("Debug: Postfix expression - function call without args\n");
        if ((yyvsp[-2].exprAttributes) != NULL) {
            (yyval.exprAttributes) = (yyvsp[-2].exprAttributes);
            insert_code((yyval.exprAttributes)->code, 1, "()");
            if ((yyval.exprAttributes)->symbol) {
                (yyval.exprAttributes)->symbol->isConstant = 0;
            }
        } else {
            yyerror("Null pointer encountered in postfix expression.");
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1637 "structfe.tab.c"
    break;

  case 7: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 142 "structfe.y"
                                                          {
        printf("Debug: Postfix expression - function call with args\n");
        (yyval.exprAttributes) = (yyvsp[-3].exprAttributes);
        print_code((yyvsp[-3].exprAttributes)->code);
        concat_code((yyval.exprAttributes)->code, (yyvsp[-1].exprAttributes)->code);
        insert_code((yyval.exprAttributes)->code, 4, (yyvsp[-3].exprAttributes)->symbol->identifier, "(", (yyvsp[-1].exprAttributes)->symbol->identifier, ")");
    }
#line 1649 "structfe.tab.c"
    break;

  case 10: /* argument_expression_list: expression  */
#line 154 "structfe.y"
                 {
        printf("Debug: Argument expression list - single expression\n");
        (yyval.exprAttributes) = createArgumentExpression((yyvsp[0].exprAttributes));
    }
#line 1658 "structfe.tab.c"
    break;

  case 11: /* argument_expression_list: argument_expression_list ',' expression  */
#line 158 "structfe.y"
                                              {
        printf("Debug: Argument expression list - multiple expressions\n");
        (yyval.exprAttributes) = addArgumentExpression((yyvsp[-2].exprAttributes), (yyvsp[0].exprAttributes));
    }
#line 1667 "structfe.tab.c"
    break;

  case 12: /* unary_expression: postfix_expression  */
#line 165 "structfe.y"
                         {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 1675 "structfe.tab.c"
    break;

  case 13: /* unary_expression: unary_operator unary_expression  */
#line 168 "structfe.y"
                                      {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
        if (est_constante((yyval.exprAttributes))) {
            insert_code((yyval.exprAttributes)->code, 2, (yyvsp[-1].string), (yyvsp[0].exprAttributes)->symbol->identifier);
        } else {
            insert_code((yyval.exprAttributes)->code, 1, (yyvsp[-1].string));
        }
    }
#line 1688 "structfe.tab.c"
    break;

  case 14: /* unary_expression: SIZEOF unary_expression  */
#line 176 "structfe.y"
                              {
        printf("Debug: SIZEOF unary expression\n");
        ExprAttributes* attr = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if (attr == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        char sizeoff[32];
        sprintf(sizeoff, "%ld", sizeof((yyvsp[0].exprAttributes)->type));
        attr->code = init_code(1, sizeoff);
        attr->type = (yyvsp[0].exprAttributes)->type;
        (yyval.exprAttributes) = attr;
    }
#line 1706 "structfe.tab.c"
    break;

  case 15: /* unary_expression: SIZEOF '(' type_specifier ')'  */
#line 189 "structfe.y"
                                    {
        printf("Debug: SIZEOF with type specifier\n");
        ExprAttributes* attr = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if (attr == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        SymbolEntry* tmp = (SymbolEntry*) malloc(sizeof(SymbolEntry));
        if (tmp == NULL) {
            free(attr);
            yyerror("Failed to allocate memory for SymbolEntry");
            exit(EXIT_FAILURE);
        }
        tmp->identifier = "";
        char sizeoff[32];
        sprintf(sizeoff, "%ld", sizeof((yyvsp[-1].exprAttributes)->type));
        attr->code = init_code(1, sizeoff);
        attr->symbol = tmp;
        (yyval.exprAttributes) = attr;
    }
#line 1731 "structfe.tab.c"
    break;

  case 16: /* unary_operator: '&'  */
#line 213 "structfe.y"
                {(yyval.string) = "&";}
#line 1737 "structfe.tab.c"
    break;

  case 17: /* unary_operator: '*'  */
#line 214 "structfe.y"
                {(yyval.string) = "*";}
#line 1743 "structfe.tab.c"
    break;

  case 18: /* unary_operator: '-'  */
#line 215 "structfe.y"
                {(yyval.string) = "-";}
#line 1749 "structfe.tab.c"
    break;

  case 19: /* multiplicative_expression: unary_expression  */
#line 219 "structfe.y"
                       {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 1757 "structfe.tab.c"
    break;

  case 20: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 222 "structfe.y"
                                                     {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type;
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "*", (yyvsp[0].exprAttributes)->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de multiplication");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1781 "structfe.tab.c"
    break;

  case 21: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 241 "structfe.y"
                                                     {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type;
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "/", (yyvsp[0].exprAttributes)->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de division");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1805 "structfe.tab.c"
    break;

  case 22: /* additive_expression: multiplicative_expression  */
#line 265 "structfe.y"
                                {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 1813 "structfe.tab.c"
    break;

  case 23: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 268 "structfe.y"
                                                        {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type;
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "+", (yyvsp[0].exprAttributes)->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération d'addition");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1837 "structfe.tab.c"
    break;

  case 24: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 287 "structfe.y"
                                                        {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type;
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "-", (yyvsp[0].exprAttributes)->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de soustraction");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1861 "structfe.tab.c"
    break;

  case 25: /* shift_expression: additive_expression  */
#line 310 "structfe.y"
    {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes); 
    }
#line 1869 "structfe.tab.c"
    break;

  case 26: /* shift_expression: shift_expression LE_OP additive_expression  */
#line 313 "structfe.y"
                                                 {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes) != NULL) {
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type; // Le type du résultat est le même que celui du premier opérande
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "<<", (yyvsp[0].exprAttributes)->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));  // Libération mémoire
                freeExprAttributes((yyvsp[0].exprAttributes));  // Libération mémoire
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de décalage à gauche");
            freeExprAttributes((yyvsp[-2].exprAttributes));  // Libération mémoire
            freeExprAttributes((yyvsp[0].exprAttributes));  // Libération mémoire
            (yyval.exprAttributes) = NULL; // Retourner NULL en cas d'erreur
        }
    }
#line 1893 "structfe.tab.c"
    break;

  case 27: /* shift_expression: shift_expression GE_OP additive_expression  */
#line 332 "structfe.y"
                                                 {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes) != NULL) {
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type; // Le type du résultat est le même que celui du premier opérande
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, ">>", (yyvsp[0].exprAttributes)->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));  // Libération mémoire
                freeExprAttributes((yyvsp[0].exprAttributes));  // Libération mémoire
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de décalage à droite");
            freeExprAttributes((yyvsp[-2].exprAttributes));  // Libération mémoire
            freeExprAttributes((yyvsp[0].exprAttributes));  // Libération mémoire
            (yyval.exprAttributes) = NULL; // Retourner NULL en cas d'erreur
        }
    }
#line 1917 "structfe.tab.c"
    break;

  case 28: /* relational_expression: shift_expression  */
#line 353 "structfe.y"
                       {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 1925 "structfe.tab.c"
    break;

  case 29: /* relational_expression: relational_expression '<' shift_expression  */
#line 356 "structfe.y"
                                                 {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes) != NULL) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "<", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE); 
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison <");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1949 "structfe.tab.c"
    break;

  case 30: /* relational_expression: relational_expression '>' shift_expression  */
#line 375 "structfe.y"
                                                 {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes) != NULL) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, ">", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison >");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1973 "structfe.tab.c"
    break;

  case 31: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 394 "structfe.y"
                                                   {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "<<", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison <<");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 1997 "structfe.tab.c"
    break;

  case 32: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 413 "structfe.y"
                                                   {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, ">>", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison >>");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL;
        }
    }
#line 2021 "structfe.tab.c"
    break;

  case 33: /* equality_expression: relational_expression  */
#line 435 "structfe.y"
    {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 2029 "structfe.tab.c"
    break;

  case 34: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 438 "structfe.y"
                                                      {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "==", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE); 
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération d'égalité");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL; // Retourner NULL en cas d'erreur
        }
    }
#line 2053 "structfe.tab.c"
    break;

  case 35: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 457 "structfe.y"
                                                      {
        // Vérifier la compatibilité des types pour l'opération de différence
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "!=", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE); // Le type du résultat est un type de base (int) pour les opérations logiques
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes));
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de différence");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL; // Retourner NULL en cas d'erreur
        }
    }
#line 2078 "structfe.tab.c"
    break;

  case 36: /* logical_and_expression: equality_expression  */
#line 481 "structfe.y"
    {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 2086 "structfe.tab.c"
    break;

  case 37: /* logical_and_expression: logical_and_expression AND_OP equality_expression  */
#line 484 "structfe.y"
                                                        {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "&&", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE);  
            } else {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes)); 
                freeExprAttributes((yyvsp[0].exprAttributes)); 
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération logique ET");
            freeExprAttributes((yyvsp[-2].exprAttributes)); 
            freeExprAttributes((yyvsp[0].exprAttributes));
            (yyval.exprAttributes) = NULL; 
        }
    }
#line 2111 "structfe.tab.c"
    break;

  case 38: /* logical_or_expression: logical_and_expression  */
#line 509 "structfe.y"
    {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 2119 "structfe.tab.c"
    break;

  case 39: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 512 "structfe.y"
                                                         {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "||", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = createType(TYPE_BASE); 
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes)); 
                freeExprAttributes((yyvsp[0].exprAttributes)); 
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération logique OU");
            freeExprAttributes((yyvsp[-2].exprAttributes)); 
            freeExprAttributes((yyvsp[0].exprAttributes)); 
            (yyval.exprAttributes) = NULL; 
        }
    }
#line 2142 "structfe.tab.c"
    break;

  case 40: /* expression: logical_or_expression  */
#line 535 "structfe.y"
                            {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 2150 "structfe.tab.c"
    break;

  case 41: /* expression: unary_expression '=' expression  */
#line 538 "structfe.y"
                                      {
        if (checkTypeCompatibility((yyvsp[-2].exprAttributes)->type, (yyvsp[0].exprAttributes)->type)) {
            (yyval.exprAttributes) = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ((yyval.exprAttributes)) {
                
                (yyval.exprAttributes)->code = insert_code(NULL, 3, (yyvsp[-2].exprAttributes)->code->codeString, "=", (yyvsp[0].exprAttributes)->code->codeString);
                (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type;  
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[0].exprAttributes)); 
                (yyval.exprAttributes) = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération d'assignation");
            freeExprAttributes((yyvsp[-2].exprAttributes)); 
            freeExprAttributes((yyvsp[0].exprAttributes)); 
            (yyval.exprAttributes) = NULL; 
        }
    }
#line 2174 "structfe.tab.c"
    break;

  case 42: /* declaration: declaration_specifiers declarator ';'  */
#line 561 "structfe.y"
    {
        SymbolEntry *sym = (yyvsp[-2].exprAttributes)->symbol;  // Assurez-vous que $1 est la bonne partie de la production pour accéder au symbole
        if (sym) {
            if (sym->isExtern) {
                (yyval.code) = init_code(3, "extern ", dttostr(sym->type->kind), " ");
            } else {
                (yyval.code) = init_code(2, dttostr(sym->type->kind), " ");
            }
            if ((yyval.code) == NULL) {
                yyerror("Allocation failure");
                freeExprAttributes((yyvsp[-2].exprAttributes));
                freeExprAttributes((yyvsp[-1].exprAttributes));
                return 1;  // Retourner avec une erreur
            }
            insert_code((yyvsp[-1].exprAttributes)->code, 1, ";\n");
            concat_code((yyval.code), (yyvsp[-1].exprAttributes)->code);
        } else {
            yyerror("SymbolEntry is NULL");
            freeExprAttributes((yyvsp[-2].exprAttributes));
            freeExprAttributes((yyvsp[-1].exprAttributes));
            return 1;  // Retourner avec une erreur
        }
    }
#line 2202 "structfe.tab.c"
    break;

  case 43: /* declaration: struct_specifier ';'  */
#line 584 "structfe.y"
                           {
        (yyval.code) = init_code(1, ";\n");
        if ((yyval.code) == NULL) {
            yyerror("Allocation failure");
            return 1;  // Retourner avec une erreur
        }
    }
#line 2214 "structfe.tab.c"
    break;

  case 44: /* declaration_specifiers: EXTERN type_specifier  */
#line 595 "structfe.y"
                            {
        if ((yyvsp[0].exprAttributes) == NULL) {
            yyerror("Allocation failure or SymbolEntry is NULL");
            YYABORT;
        }
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
        (yyval.exprAttributes)->symbol->isExtern = 1;
    }
#line 2227 "structfe.tab.c"
    break;

  case 45: /* declaration_specifiers: type_specifier  */
#line 603 "structfe.y"
                     {
        if ((yyvsp[0].exprAttributes) == NULL) {
            yyerror("Allocation failure or SymbolEntry is NULL");
            YYABORT;
        }
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
        (yyval.exprAttributes)->symbol->isExtern = 0;
    }
#line 2240 "structfe.tab.c"
    break;

  case 46: /* type_specifier: VOID  */
#line 614 "structfe.y"
           {
        (yyval.exprAttributes) = malloc(sizeof(ExprAttributes));
        if ((yyval.exprAttributes) == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            YYABORT;
        }
        (yyval.exprAttributes)->type = createType(TYPE_VOID);
        if ((yyval.exprAttributes)->type == NULL) {
            free((yyval.exprAttributes));
            yyerror("Failed to create type TYPE_VOID");
            YYABORT;
        }
        (yyval.exprAttributes)->code = NULL;
        (yyval.exprAttributes)->symbol = malloc(sizeof(SymbolEntry));
        if ((yyval.exprAttributes)->symbol == NULL) {
            free((yyval.exprAttributes)->type);
            free((yyval.exprAttributes));
            yyerror("Failed to allocate memory for SymbolEntry");
            YYABORT;
        }
        (yyval.exprAttributes)->symbol->isExtern = 0;
    }
#line 2267 "structfe.tab.c"
    break;

  case 47: /* type_specifier: INT  */
#line 636 "structfe.y"
          {
        (yyval.exprAttributes) = malloc(sizeof(ExprAttributes));
        if ((yyval.exprAttributes) == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            YYABORT;
        }
        (yyval.exprAttributes)->type = createType(TYPE_INT);
        if ((yyval.exprAttributes)->type == NULL) {
            free((yyval.exprAttributes));
            yyerror("Failed to create type TYPE_INT");
            YYABORT;
        }
        (yyval.exprAttributes)->code = NULL;
        (yyval.exprAttributes)->symbol = malloc(sizeof(SymbolEntry));
        if ((yyval.exprAttributes)->symbol == NULL) {
            free((yyval.exprAttributes)->type);
            free((yyval.exprAttributes));
            yyerror("Failed to allocate memory for SymbolEntry");
            YYABORT;
        }
        (yyval.exprAttributes)->symbol->isExtern = 0;
    }
#line 2294 "structfe.tab.c"
    break;

  case 48: /* type_specifier: struct_specifier  */
#line 658 "structfe.y"
                       {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 2302 "structfe.tab.c"
    break;

  case 49: /* struct_specifier: STRUCT IDENTIFIER '{' struct_declaration_list '}'  */
#line 665 "structfe.y"
    {
        if (!(yyvsp[-1].exprAttributes)) {
            yyerror("Internal error: struct_declaration_list returned NULL");
            exit(EXIT_FAILURE);
        }
        if (!(yyvsp[-1].exprAttributes)->code || !(yyvsp[-1].exprAttributes)->type) {
            yyerror("Incomplete exprAttributes from struct_declaration_list");
            freeExprAttributes((yyvsp[-1].exprAttributes));
            exit(EXIT_FAILURE);
        }
        (yyval.exprAttributes) = (yyvsp[-1].exprAttributes); 
        print_code((yyval.exprAttributes)->code); 
    }
#line 2320 "structfe.tab.c"
    break;

  case 50: /* struct_specifier: STRUCT '{' struct_declaration_list '}'  */
#line 679 "structfe.y"
    {
        if (!(yyvsp[-1].exprAttributes) || !(yyvsp[-1].exprAttributes)->code || !(yyvsp[-1].exprAttributes)->type) {
            yyerror("Incomplete or missing exprAttributes for anonymous struct");
            exit(EXIT_FAILURE);
        }
        (yyval.exprAttributes) = (yyvsp[-1].exprAttributes);
        print_code((yyval.exprAttributes)->code); 
    }
#line 2333 "structfe.tab.c"
    break;

  case 51: /* struct_specifier: STRUCT IDENTIFIER  */
#line 688 "structfe.y"
    {
        ExprAttributes* attr = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if (!attr) {
            yyerror("Failed to allocate memory for exprAttributes");
            exit(EXIT_FAILURE);
        }
        char* identifier = (char*)(yyvsp[0].string);
        attr->code = init_code(1,identifier); ;
        attr->type = lookupStructType((yyvsp[0].string)); // Suppose this returns a valid Type*
        attr->symbol = NULL; // No direct symbol associated here

        if (!attr->code || !attr->type) {
            yyerror("Failed to initialize exprAttributes correctly");
            free(attr);
            exit(EXIT_FAILURE);
        }

        (yyval.exprAttributes) = attr;
        print_code((yyval.exprAttributes)->code); // Pour débogage
    }
#line 2358 "structfe.tab.c"
    break;

  case 52: /* struct_declaration_list: struct_declaration  */
#line 711 "structfe.y"
                         {
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes); 
    }
#line 2366 "structfe.tab.c"
    break;

  case 53: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 714 "structfe.y"
                                                 {
        if ((yyval.exprAttributes) == NULL) (yyval.exprAttributes) = (yyvsp[-1].exprAttributes); 
        if ((yyvsp[-1].exprAttributes)->code && (yyvsp[0].exprAttributes)->code) { 
            concat_code((yyvsp[-1].exprAttributes)->code, (yyvsp[0].exprAttributes)->code); 
        }
        (yyval.exprAttributes) = (yyvsp[-1].exprAttributes); 
        freeExprAttributes((yyvsp[0].exprAttributes));
    }
#line 2379 "structfe.tab.c"
    break;

  case 54: /* struct_declaration: type_specifier declarator ';'  */
#line 727 "structfe.y"
                                         {
        (yyval.exprAttributes) = malloc(sizeof(ExprAttributes));
        if ((yyval.exprAttributes) == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        if ((yyvsp[-2].exprAttributes) && (yyvsp[-1].exprAttributes)) {
            (yyval.exprAttributes)->type = (yyvsp[-2].exprAttributes)->type;  
            (yyval.exprAttributes)->symbol = (yyvsp[-1].exprAttributes)->symbol;  
            (yyval.exprAttributes)->code = init_code(1, ";");
            if ((yyvsp[-1].exprAttributes)->code) {
                concat_code((yyval.exprAttributes)->code, (yyvsp[-1].exprAttributes)->code);
            }
        } else {
            yyerror("Type specifier or declarator returned NULL");
            free((yyval.exprAttributes));
            (yyval.exprAttributes) = NULL;
            return 1; 
        }
     
    }
#line 2405 "structfe.tab.c"
    break;

  case 55: /* declarator: '*' direct_declarator  */
#line 751 "structfe.y"
                            {
        (yyval.exprAttributes) = malloc(sizeof(ExprAttributes));
        if ((yyval.exprAttributes) == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        (yyval.exprAttributes)->code = init_code(1, "*");
        if ((yyvsp[0].exprAttributes) && (yyvsp[0].exprAttributes)->code) {
            concat_code((yyval.exprAttributes)->code, (yyvsp[0].exprAttributes)->code);
        } else {
            yyerror("Code from direct_declarator is NULL");
            free((yyval.exprAttributes));
            return 1;
        }
        if ((yyvsp[0].exprAttributes) && (yyvsp[0].exprAttributes)->symbol) {
            (yyvsp[0].exprAttributes)->symbol->type = createType(TYPE_POINTER);
            (yyval.exprAttributes)->symbol = (yyvsp[0].exprAttributes)->symbol;
        } else {
            yyerror("Symbol from direct_declarator is NULL or not properly initialized");
            free((yyval.exprAttributes));
            return 1;
        }
    }
#line 2433 "structfe.tab.c"
    break;

  case 56: /* declarator: direct_declarator  */
#line 774 "structfe.y"
                        {
        if ((yyvsp[0].exprAttributes) == NULL) {
            yyerror("direct_declarator returned NULL");
            (yyval.exprAttributes) = NULL;
            return 1;
        }
        (yyval.exprAttributes) = (yyvsp[0].exprAttributes);
    }
#line 2446 "structfe.tab.c"
    break;

  case 57: /* direct_declarator: IDENTIFIER  */
#line 786 "structfe.y"
                 {
        if ((yyvsp[0].string) == NULL || strlen((yyvsp[0].string)) == 0) {
            yyerror("IDENTIFIER is NULL or empty");
            (yyval.exprAttributes) = NULL;
            YYABORT; // Arrêtez l'analyse si l'identifiant est nul ou vide
        } else {
            // Allouer et initialiser ExprAttributes pour stocker les résultats
            (yyval.exprAttributes) = (ExprAttributes*) malloc(sizeof(ExprAttributes));
            if (!(yyval.exprAttributes)) {
                yyerror("Failed to allocate memory for ExprAttributes");
                exit(EXIT_FAILURE);
            }
            // Initialiser le code avec l'identifiant
            (yyval.exprAttributes)->code = init_code(1, (yyvsp[0].string));
            (yyval.exprAttributes)->symbol = (SymbolEntry*) malloc(sizeof(SymbolEntry));
            if (!(yyval.exprAttributes)->symbol) {
                free((yyval.exprAttributes));
                yyerror("Failed to allocate memory for SymbolEntry");
                exit(EXIT_FAILURE);
            }
            (yyval.exprAttributes)->symbol->identifier = strdup((yyvsp[0].string));
            if (!(yyval.exprAttributes)->symbol->identifier) {
                free((yyval.exprAttributes)->symbol);
                free((yyval.exprAttributes));
                yyerror("Failed to duplicate identifier");
                exit(EXIT_FAILURE);
            }
            (yyval.exprAttributes)->symbol->type = NULL;
        }
    }
#line 2481 "structfe.tab.c"
    break;

  case 58: /* direct_declarator: '(' declarator ')'  */
#line 817 "structfe.y"
    {
        (yyval.exprAttributes) = (yyvsp[-1].exprAttributes);
    }
#line 2489 "structfe.tab.c"
    break;

  case 59: /* direct_declarator: direct_declarator '(' parameter_list ')'  */
#line 821 "structfe.y"
    {
        if ((yyvsp[-3].exprAttributes) != NULL && (yyvsp[-1].code) != NULL) {
            (yyval.exprAttributes) = (yyvsp[-3].exprAttributes);
            insert_code((yyval.exprAttributes)->code, 1, "(");
            concat_code((yyval.exprAttributes)->code, (yyvsp[-1].code));
            insert_code((yyval.exprAttributes)->code, 1, ")");
        } else {
            fprintf(stderr, "Null pointer encountered in parameter list\n");
        }
    }
#line 2504 "structfe.tab.c"
    break;

  case 60: /* direct_declarator: direct_declarator '(' ')'  */
#line 832 "structfe.y"
   {
        if ((yyvsp[-2].exprAttributes) == NULL) {
            yyerror("direct_declarator is NULL");
            (yyval.exprAttributes) = NULL;
            YYABORT;
        }
        (yyval.exprAttributes) = (yyvsp[-2].exprAttributes);
        insert_code((yyval.exprAttributes)->code, 2, (yyvsp[-2].exprAttributes)->code->codeString, "()");
    }
#line 2518 "structfe.tab.c"
    break;

  case 61: /* parameter_list: parameter_declaration  */
#line 845 "structfe.y"
                                {
            
           (yyval.code) = (yyvsp[0].code);
        }
#line 2527 "structfe.tab.c"
    break;

  case 62: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 849 "structfe.y"
                                                   {
           
             (yyval.code) = (yyvsp[-2].code);
            insert_code((yyval.code), 1, ", ");
            concat_code((yyval.code), (yyvsp[0].code)); 
        }
#line 2538 "structfe.tab.c"
    break;

  case 63: /* parameter_declaration: declaration_specifiers declarator  */
#line 858 "structfe.y"
                                        {
        SymbolEntry* paramEntry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
        if (!paramEntry) {
            yyerror("Allocation failure for SymbolEntry");
            freeExprAttributes((yyvsp[-1].exprAttributes));
            freeExprAttributes((yyvsp[0].exprAttributes));
            return 1;
        }
        paramEntry->type = (yyvsp[-1].exprAttributes)->symbol->type;
        (yyval.code) = init_code(0);
        concat_code((yyval.code), (yyvsp[-1].exprAttributes)->code);
        concat_code((yyval.code), (yyvsp[0].exprAttributes)->code);
        // Libération mémoire des attributs
        freeExprAttributes((yyvsp[-1].exprAttributes));
        freeExprAttributes((yyvsp[0].exprAttributes));
    }
#line 2559 "structfe.tab.c"
    break;

  case 64: /* statement: compound_statement  */
#line 876 "structfe.y"
                        {
        (yyval.code) = (yyvsp[0].code); 
    	}
#line 2567 "structfe.tab.c"
    break;

  case 65: /* statement: expression_statement  */
#line 879 "structfe.y"
                              {
        (yyval.code) = (yyvsp[0].code); 
    	}
#line 2575 "structfe.tab.c"
    break;

  case 66: /* statement: selection_statement  */
#line 882 "structfe.y"
                             {
        (yyval.code) = (yyvsp[0].code); 
    	}
#line 2583 "structfe.tab.c"
    break;

  case 67: /* statement: iteration_statement  */
#line 885 "structfe.y"
                             {
        (yyval.code) = (yyvsp[0].code); 
    	}
#line 2591 "structfe.tab.c"
    break;

  case 68: /* statement: jump_statement  */
#line 888 "structfe.y"
                         {
        (yyval.code) = (yyvsp[0].code); 
   	 }
#line 2599 "structfe.tab.c"
    break;

  case 69: /* compound_statement: '{' '}'  */
#line 895 "structfe.y"
    {
        (yyval.code) = init_code(0);
    }
#line 2607 "structfe.tab.c"
    break;

  case 70: /* compound_statement: '{' statement_list '}'  */
#line 899 "structfe.y"
    {
        (yyval.code) = (yyvsp[-1].code); 
    }
#line 2615 "structfe.tab.c"
    break;

  case 71: /* compound_statement: '{' declaration_list '}'  */
#line 903 "structfe.y"
    {
        (yyval.code) = (yyvsp[-1].code); 
    }
#line 2623 "structfe.tab.c"
    break;

  case 72: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 907 "structfe.y"
    {
        (yyval.code) = (yyvsp[-2].code); 
        concat_code((yyval.code), (yyvsp[-1].code));
    }
#line 2632 "structfe.tab.c"
    break;

  case 73: /* declaration_list: declaration  */
#line 915 "structfe.y"
                     {
        (yyval.code) = (yyvsp[0].code); 
    	}
#line 2640 "structfe.tab.c"
    break;

  case 74: /* declaration_list: declaration_list declaration  */
#line 918 "structfe.y"
                                       {
        (yyval.code) = (yyvsp[-1].code); 
        concat_code((yyval.code), (yyvsp[0].code));
	}
#line 2649 "structfe.tab.c"
    break;

  case 75: /* statement_list: statement  */
#line 926 "structfe.y"
    {
        (yyval.code) = (yyvsp[0].code); 
    }
#line 2657 "structfe.tab.c"
    break;

  case 76: /* statement_list: statement_list statement  */
#line 930 "structfe.y"
    {
        (yyval.code) = (yyvsp[-1].code); 
        concat_code((yyval.code), (yyvsp[0].code)); 
    }
#line 2666 "structfe.tab.c"
    break;

  case 77: /* expression_statement: ';'  */
#line 939 "structfe.y"
    {
        (yyval.code) = init_code(0);  
    }
#line 2674 "structfe.tab.c"
    break;

  case 78: /* expression_statement: expression ';'  */
#line 943 "structfe.y"
    {
       if (strrchr((yyvsp[-1].exprAttributes)->code->codeString, ';') == NULL) {
            insert_code((yyvsp[-1].exprAttributes)->code, 1, ";\n"); 
        }
        (yyval.code) = (yyvsp[-1].exprAttributes)->code;   
    }
#line 2685 "structfe.tab.c"
    break;

  case 79: /* selection_statement: IF '(' expression ')' statement  */
#line 953 "structfe.y"
    {
        char* etq_if = new_et();
        char* etq_else = new_et();

        if ((yyvsp[-2].exprAttributes)->type->kind != TYPE_INT) {
        yyerror("Condition must be an INT!");
    }


        (yyval.code) = (yyvsp[-2].exprAttributes)->code;
        insert_code((yyval.code), 7, "if (!", (yyvsp[-2].exprAttributes)->symbol->identifier, ") goto ", etq_else, ";\n", etq_if, ":\n");
        concat_code((yyval.code), (yyvsp[0].code));
        insert_code((yyval.code), 2, etq_else, ":\n");

    }
#line 2705 "structfe.tab.c"
    break;

  case 80: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 969 "structfe.y"
    {
        char* etq_true = new_et();
        char* etq_false = new_et();
        char* etq_def = new_et();

        if ((yyvsp[-4].exprAttributes)->type->kind != TYPE_INT) {
        yyerror("Condition must be an INT!");
    }

        (yyval.code) = (yyvsp[-4].exprAttributes)->code;
        insert_code((yyval.code), 7, "if (!", (yyvsp[-4].exprAttributes)->symbol->identifier, ") goto ", etq_false, ";\n", etq_true, ":\n");
        concat_code((yyval.code), (yyvsp[-2].code));
        insert_code((yyval.code), 5, "goto ", etq_def, ";\n", etq_false, ":\n");
        concat_code((yyval.code), (yyvsp[0].code));
        insert_code((yyval.code), 5, "goto ", etq_def, ";\n", etq_def, ":\n");
    }
#line 2726 "structfe.tab.c"
    break;

  case 81: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 990 "structfe.y"
    {
        char* etq_debut = new_et();
        char* etq_fin = new_et();

        // Vérifiez que le type est `TYPE_INT`
        if ((yyvsp[-2].exprAttributes)->type->kind != TYPE_INT) {
            yyerror("Condition must be an INT!");
        }

        (yyval.code) = (yyvsp[-2].exprAttributes)->code;
        insert_code((yyval.code), 6, etq_debut, ":\nif (!", (yyvsp[-2].exprAttributes)->symbol->identifier, ") goto ", etq_fin, "\n");
        concat_code((yyval.code), (yyvsp[0].code));
        insert_code((yyval.code), 2, "goto ", etq_debut, "\n", etq_fin, ":\n");
    }
#line 2745 "structfe.tab.c"
    break;

  case 82: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 1005 "structfe.y"
    {
        char* etq_debut = new_et();
        char* etq_condition = new_et();
        char* etq_fin = new_et();

        // Vérifiez que le type est `TYPE_INT`
        if ((yyvsp[-2].exprAttributes)->type->kind != TYPE_INT) {
            yyerror("Condition must be un INT!");
        }

        Code* code3 = (yyvsp[-2].exprAttributes)->code;

        (yyval.code) = (yyvsp[-2].exprAttributes)->code;
        insert_code((yyval.code), 4, etq_debut, ":\nif (!", (yyvsp[-2].exprAttributes)->symbol->identifier, ") goto ", etq_fin, "\n");
        concat_code((yyval.code), (yyvsp[0].code));
        concat_code((yyval.code), code3);
        insert_code((yyval.code), 2, "goto ", etq_debut, "\n", etq_fin, ":\n");
    }
#line 2768 "structfe.tab.c"
    break;

  case 83: /* jump_statement: RETURN ';'  */
#line 1029 "structfe.y"
    {
        (yyval.code) = init_code(1, "return;\n");
    }
#line 2776 "structfe.tab.c"
    break;

  case 84: /* jump_statement: RETURN expression ';'  */
#line 1033 "structfe.y"
    {
        char* tmp = malloc(strlen((yyvsp[-1].exprAttributes)->symbol->identifier) + 10);
        sprintf(tmp, "return %s;\n", (yyvsp[-1].exprAttributes)->symbol->identifier);
        insert_code((yyvsp[-1].exprAttributes)->code, 1, tmp);
        free(tmp); 
        (yyval.code) = (yyvsp[-1].exprAttributes)->code;
    }
#line 2788 "structfe.tab.c"
    break;

  case 85: /* program: external_declaration  */
#line 1045 "structfe.y"
        {
                print_code((yyvsp[0].code));
                free_code((yyvsp[0].code));
        }
#line 2797 "structfe.tab.c"
    break;

  case 86: /* program: program external_declaration  */
#line 1050 "structfe.y"
        {
                print_code((yyvsp[0].code));
                free_code((yyvsp[0].code));
        }
#line 2806 "structfe.tab.c"
    break;

  case 87: /* external_declaration: function_definition  */
#line 1058 "structfe.y"
    {
        (yyval.code) = (yyvsp[0].code); 
    }
#line 2814 "structfe.tab.c"
    break;

  case 88: /* external_declaration: declaration  */
#line 1062 "structfe.y"
    {
        (yyval.code) = (yyvsp[0].code); 
    }
#line 2822 "structfe.tab.c"
    break;

  case 89: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 1070 "structfe.y"
    {
        Code* code = NULL;
        if ((yyvsp[-2].exprAttributes)->symbol->isExtern) {
            code = init_code(2, "extern ", dttostr((yyvsp[-2].exprAttributes)->symbol->type->kind));
        } else {
            code = init_code(1, dttostr((yyvsp[-2].exprAttributes)->symbol->type->kind));
        }

        concat_code(code, (yyvsp[-1].exprAttributes)->code);
        insert_code(code, 1, " {\n");
        concat_code(code, declare_var(table));
        concat_code(code, (yyvsp[0].code));
        insert_code(code, 1, "}\n");
        reset_table(table);
        (yyval.code) = code;
    }
#line 2843 "structfe.tab.c"
    break;


#line 2847 "structfe.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1091 "structfe.y"


