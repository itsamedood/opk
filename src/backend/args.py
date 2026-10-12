from sys import argv, exit


class Args:
  HELP_MSG = """opk - itsamedood
Usage: opk [-help] | [-version] | [-verbose]
        | new [-parent <parent> -app <app> -username <username> -password <password>]
        | get <parent>
        | wipe
        | changekey [currentkey] [newkey]

Commands:
  new               | Add a new data set. You'll be prompted for parent, app, username, and password fields.
  get               | Retrieve saved data via the parent name.
  wipe              | Wipes all your saved data. You'll be prompted for a new masterkey if you run this.
  changekey         | Change your masterkey, provided you know the current one. You'll be prompted for the current and new key.

Flags:
  -help             | Displays this menu and exits.
  -verbose          | Prints extra info for debugging.
  -version          | Displays current version and exits.
  -silent           | Runs without printing anything. This will cause verbose to not do anything. Prompts will still work.
  -parent           | Name this data should be under.
  -app              | App or website this data is for.
  -username         | Email or username.
  -password         | Password to use.
"""

  VERSION = "0.0.1"  # Idk how to version things I can't lie-

  given: list[tuple[str, str | bool]] = []

  def get(self) -> list[tuple[str, str | bool]]:
    """ Populates `self.given`. """

    flags = [a[1:] for a in argv if a[0] == '-']
    flagswithargs = [f for f in flags if '=' in f]
    verbose = False
    silent = False

    for flag in flags:
      if flag in flagswithargs: continue

      match flag:
        case "help" | 'h':
          print(self.HELP_MSG)
          exit(0)

        case "version" | 'v':
          print(f"v{self.VERSION}")

        case "verbose" | 'vb':
          if not silent: verbose = True
          self.given.append(("verbose", True))

        case "silent" | 's':
          silent, verbose = True, False
          self.given.append(("silent", True))

        case _:
          if not silent:
            print("Unknown flag: %s" %flag)
            exit(1)

    for flag in flagswithargs:
      name, value = flag.split('=', 1)

      match name:
        case "parent":
          if verbose: print("Parent: %s" %value)

        case "app":
          if verbose: print("App: %s" %value)

        case "username":
          if verbose: print("Username: %s" %value)

        case "password":
          if verbose: print("Password: %s" %value)

        case _:
          if not silent: print("Unknown flag: %s" %name)
          exit(1)

      self.given.append((name, value))  # Only makes it here with valid flags, so we can have one append here.

    return self.given

  def has(self, flag: str) -> bool:
    """ Returns `True` if `flag` was provided. """

    return len([t for t in self.given if t[0] == flag]) > 0
