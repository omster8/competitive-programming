<!DOCTYPE html>
<html lang="en">
<head>
    <title>Login - MCPT: Mackenzie Competitive Programming Team</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <meta name="keywords" content="MCPT,Canadian,WLMCI,WLMOJ,William Lyon Mackenzie,online judge,programming,code,contest,Canada,Ontario,Toronto,grade,interactive,Moose">
    <meta id="viewport" name="viewport" content="width=device-width, initial-scale=1">
    <!-- Favicons-->
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-57x57.png">
    <link rel="apple-touch-icon" sizes="60x60" href="/apple-touch-icon-60x60.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-72x72.png">
    <link rel="apple-touch-icon" sizes="76x76" href="/apple-touch-icon-76x76.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114x114.png">
    <link rel="apple-touch-icon" sizes="120x120" href="/apple-touch-icon-120x120.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144x144.png">
    <link rel="apple-touch-icon" sizes="152x152" href="/apple-touch-icon-152x152.png">
    <link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png">
    <link rel="icon" type="image/png" href="/favicon-32x32.png" sizes="32x32">
    <link rel="icon" type="image/png" href="/android-chrome-192x192.png" sizes="192x192">
    <link rel="icon" type="image/png" href="/favicon-96x96.png" sizes="96x96">
    <link rel="icon" type="image/png" href="/favicon-16x16.png" sizes="16x16">
    <link rel="manifest" href="/manifest.json">
    <meta name="msapplication-TileColor" content="#3737B4">
    <meta name="msapplication-TileImage" content="/mstile-144x144.png">
    <meta name="theme-color" content="#3737B4">
    <meta property="og:site_name" content="MCPT: Mackenzie Competitive Programming Team">
    <meta property="og:url"
          content="http://mcpt.ca/accounts/login/?next=/src/14652/raw">
    <!--[if lt IE 9]>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7.3/html5shiv.min.js"></script>
    <script>window.bad_browser = true</script>
    <![endif]-->
        <link rel="stylesheet" href="/static/style.css">
            <link rel="stylesheet" href="/static/pygment-github.css">
        <link rel="stylesheet" href="/static/libs/fontawesome/font-awesome.css">        <link rel="stylesheet" type="text/css" href="/static/libs/featherlight/featherlight.min.css">
        <link rel="stylesheet" type="text/css" href="/static/libs/clipboard/tooltip.css">
        <link rel="stylesheet" type="text/css" href="/static/libs/select2/select2.css">
    <link rel="canonical"
          href="http://mcpt.ca/accounts/login/?next=/src/14652/raw">
    <style>
        #login-panel {
            display: inline-block;
            position: relative;
            margin: 5em auto auto -10em;
            top: 40%;
            left: 50%;
        }

        h4 {
            padding-top: 1em;
        }

        .social {
            display: inline;
            font-size: 2.3em;
            float: none;
        }

        .google-icon i {
            color: #DD4B38;
        }

        .facebook-icon i {
            color: #133783;
        }

        .github-icon i {
            color: black;
        }
    </style>

        <script>

(function(globals) {

  var django = globals.django || (globals.django = {});

  
  django.pluralidx = function(count) { return (count == 1) ? 0 : 1; };
  

  /* gettext library */

  django.catalog = django.catalog || {};
  

  if (!django.jsi18n_initialized) {
    django.gettext = function(msgid) {
      var value = django.catalog[msgid];
      if (typeof(value) == 'undefined') {
        return msgid;
      } else {
        return (typeof(value) == 'string') ? value : value[0];
      }
    };

    django.ngettext = function(singular, plural, count) {
      var value = django.catalog[singular];
      if (typeof(value) == 'undefined') {
        return (count == 1) ? singular : plural;
      } else {
        return value.constructor === Array ? value[django.pluralidx(count)] : value;
      }
    };

    django.gettext_noop = function(msgid) { return msgid; };

    django.pgettext = function(context, msgid) {
      var value = django.gettext(context + '\x04' + msgid);
      if (value.indexOf('\x04') != -1) {
        value = msgid;
      }
      return value;
    };

    django.npgettext = function(context, singular, plural, count) {
      var value = django.ngettext(context + '\x04' + singular, context + '\x04' + plural, count);
      if (value.indexOf('\x04') != -1) {
        value = django.ngettext(singular, plural, count);
      }
      return value;
    };

    django.interpolate = function(fmt, obj, named) {
      if (named) {
        return fmt.replace(/%\(\w+\)s/g, function(match){return String(obj[match.slice(2,-2)])});
      } else {
        return fmt.replace(/%s/g, function(match){return String(obj.shift())});
      }
    };


    /* formatting library */

    django.formats = {
    "DATETIME_FORMAT": "N j, Y, P",
    "DATETIME_INPUT_FORMATS": [
      "%Y-%m-%d %H:%M:%S",
      "%Y-%m-%d %H:%M:%S.%f",
      "%Y-%m-%d %H:%M",
      "%Y-%m-%d",
      "%m/%d/%Y %H:%M:%S",
      "%m/%d/%Y %H:%M:%S.%f",
      "%m/%d/%Y %H:%M",
      "%m/%d/%Y",
      "%m/%d/%y %H:%M:%S",
      "%m/%d/%y %H:%M:%S.%f",
      "%m/%d/%y %H:%M",
      "%m/%d/%y"
    ],
    "DATE_FORMAT": "N j, Y",
    "DATE_INPUT_FORMATS": [
      "%Y-%m-%d",
      "%m/%d/%Y",
      "%m/%d/%y"
    ],
    "DECIMAL_SEPARATOR": ".",
    "FIRST_DAY_OF_WEEK": 0,
    "MONTH_DAY_FORMAT": "F j",
    "NUMBER_GROUPING": 3,
    "SHORT_DATETIME_FORMAT": "m/d/Y P",
    "SHORT_DATE_FORMAT": "m/d/Y",
    "THOUSAND_SEPARATOR": ",",
    "TIME_FORMAT": "P",
    "TIME_INPUT_FORMATS": [
      "%H:%M:%S",
      "%H:%M:%S.%f",
      "%H:%M"
    ],
    "YEAR_MONTH_FORMAT": "F Y"
  };

    django.get_format = function(format_type) {
      var value = django.formats[format_type];
      if (typeof(value) == 'undefined') {
        return format_type;
      } else {
        return value;
      }
    };

    /* add to global namespace */
    globals.pluralidx = django.pluralidx;
    globals.gettext = django.gettext;
    globals.ngettext = django.ngettext;
    globals.gettext_noop = django.gettext_noop;
    globals.pgettext = django.pgettext;
    globals.npgettext = django.npgettext;
    globals.interpolate = django.interpolate;
    globals.get_format = django.get_format;

    django.jsi18n_initialized = true;
  }

}(this));

</script>
            <script src="/static/libs/jquery-3.4.1.min.js"></script>
        <script src="/static/libs/jquery-cookie.js"></script>
        <script src="/static/libs/jquery-taphold.js"></script>
        <script src="/static/libs/jquery.unveil.js"></script>
        <script src="/static/libs/moment.js"></script>
        <script src="/static/libs/select2/select2.js"></script>
        <script src="/static/common.js"></script>
        <script>
            moment.locale('en');
            $(function () {
                $('img.unveil').unveil(200);
            });
        </script>

        <script>window.user = {};</script>



    <noscript>
        <style>
            #content {
                margin: 80px auto auto;
            }

            #navigation {
                top: 27px;
            }
        </style>
    </noscript>
</head>
<body>
<svg width="0" height="0" style="display: block">
    <defs>
        <clipPath id="rating-clip"><circle cx="8" cy="8" r="7"/></clipPath>
    </defs>
</svg>
<nav id="navigation" class="unselectable">
    <div id="nav-container">
        <a id="navicon" href="javascript:void(0)"><i class="fa fa-bars"></i></a>
        <ul id="nav-list">
            <li class="home-nav-element"><a href="/">    <img src="/static/icons/logo.png" alt="MCPT" height="44"
         onerror="this.src=&quot;/static/icons/logo.png&quot;; this.onerror=null" style="border: none">
</a></li>
            <li class="home-nav-element"><span class="nav-divider"></span></li>
            <li class="home-menu-item"><a href="/" class="nav-home">Home</a></li>
                <li>
                    <a href="/problems/" class="nav-problems">
                        Problems
                    </a>
                </li>
                <li>
                    <a href="/submissions/" class="nav-submit">
                        Submissions
                    </a>
                </li>
                <li>
                    <a href="/users/" class="nav-user">
                        Users
                    </a>
                </li>
                <li>
                    <a href="/contests/" class="nav-contest">
                        Contests
                    </a>
                </li>
                <li>
                    <a href="/about/" class="nav-about">
                        About
                    </a>
<ul>                <li>
                    <a href="/contact/" class="nav-contact">
                        Contact
                    </a>
                </li>
                <li>
                    <a href="/status/" class="nav-status">
                        Status
                    </a>
                </li>
                <li>
                    <a href="/faq/" class="nav-faq">
                        FAQ
                    </a>
                </li>
                <li>
                    <a href="/achievements/" class="nav-achieve">
                        Achievements
                    </a>
                </li>
                <li>
                    <a href="https://archive.mcpt.ca" class="nav-archived">
                        Archived Site
                    </a>
                </li>
</ul>                </li>
                <li>
                    <a href="/lessons" class="nav-lessons">
                        Lessons
                    </a>
<ul>                <li>
                    <a href="/lessons/learning/" class="nav-girls">
                        Learning
                    </a>
                </li>
                <li>
                    <a href="/lessons/competitive/" class="nav-comp">
                        Competitive
                    </a>
                </li>
                <li>
                    <a href="/lessons/archive/" class="nav-alessons">
                        Archive
                    </a>
                </li>
</ul>                </li>
        </ul>

        <span id="user-links">
                <span class="anon">
                    <a href="/accounts/login/?next="><b>Log in</b></a>
                    &nbsp;or&nbsp;
                    <a href="/accounts/register/"><b>Sign up</b></a>
                </span>
        </span>
    </div>
    <div id="nav-shadow"></div>
</nav>
<div id="page-container">
    <noscript>
        <div id="noscript">This site works best with JavaScript enabled.</div>
    </noscript>
    <br>
    <main id="content">
            <h2 style="color:#393630; display:inline">
Login            </h2>
            <hr>
        <div id="content-body">    <div id="login-panel">
        <form action="" method="post" class="form-area">
<input type='hidden' name='csrfmiddlewaretoken' value='Vh4YdTwZZgX0815yRUsmOpx7X8ZhcpkQru2O5vcyMx3Mt0fpQrAVew5e9RUn3Od1' />            <table border="0" style="text-align:left">
                <tr>
                    <th><i class="fa fa-user fa-fw"></i>
                    </th>
                    <td><input type="text" name="username" autofocus placeholder="Username" required id="id_username">
                    </td>
                </tr>
                <tr>
                    <th><i class="fa fa-key fa-fw"></i>
                    </th>
                    <td><input type="password" name="password" placeholder="Password" required id="id_password">
                    </td>
                </tr>
            </table>
            <hr>
            <button style="float:right;" type="submit">Login!</button>
            <input type="hidden" name="next" value="/src/14652/raw">
        </form>
        <br><a href="/accounts/password/reset/">Forgot your password?</a>

    </div>
</div>
    </main>



    <footer>
        <span id="footer-content">
            <br>
                <span id="quote">Something went wrong here.</span> |
<a style="color: #808080"><b>Mackenzie's CPT Judge</b></a> |
<a style="color: #808080" href="/tos/">Terms of Service</a> |
<a style="color: #808080" href="https://github.com/MCPT/wlmoj">Source code</a>

<!--Quote control.-->
<style>
  #quote abbr {
    border: none;
    display: inline;
    text-decoration: none;
  }
</style>
<script>
  jQuery.getJSON("/static/quotes.json", function (quotes) {
    let quote = quotes[Math.floor(Math.random() * quotes.length)]
    document.getElementById("quote").innerHTML = (quote["tooltip"] ? `<abbr title="${quote["tooltip"]}">${quote["quote"]}</abbr>` : quote["quote"]);
  });
</script> |
            <form action="/i18n/setlang/" method="post" style="display: inline">
<input type='hidden' name='csrfmiddlewaretoken' value='Vh4YdTwZZgX0815yRUsmOpx7X8ZhcpkQru2O5vcyMx3Mt0fpQrAVew5e9RUn3Od1' />            <input name="next" type="hidden" value="/accounts/login/?next=/src/14652/raw">
            <select name="language" onchange="form.submit()" style="height: 1.5em">
                    <option value="ca" >
                        català (ca)
                    </option>
                    <option value="de" >
                        Deutsch (de)
                    </option>
                    <option value="en" selected>
                        English (en)
                    </option>
                    <option value="es" >
                        español (es)
                    </option>
                    <option value="fr" >
                        français (fr)
                    </option>
                    <option value="hr" >
                        Hrvatski (hr)
                    </option>
                    <option value="hu" >
                        Magyar (hu)
                    </option>
                    <option value="ja" >
                        日本語 (ja)
                    </option>
                    <option value="ko" >
                        한국어 (ko)
                    </option>
                    <option value="pt" >
                        Português (pt)
                    </option>
                    <option value="ro" >
                        Română (ro)
                    </option>
                    <option value="ru" >
                        Русский (ru)
                    </option>
                    <option value="sr-latn" >
                        srpski (latinica) (sr-latn)
                    </option>
                    <option value="tr" >
                        Türkçe (tr)
                    </option>
                    <option value="vi" >
                        Tiếng Việt (vi)
                    </option>
                    <option value="zh-hans" >
                        简体中文 (zh-hans)
                    </option>
                    <option value="zh-hant" >
                        繁體中文 (zh-hant)
                    </option>
            </select>
          </form>
        </span>
    </footer>
</div>
</body>
</html>