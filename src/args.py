from sys import argv, exit


class Args:
  HELP_MSG = """opk - itsamedood
Usage: opk [-help] | [-verbose] -parent <parent> -app <app> -username <username> -password <password>

Commands:
  new               | Add a new data set. Requires the -parent, -app, -username, and -password flags.
  get               | Retrieve saved data via the parent name.
  wipe              | Wipes all your saved data. You'll be prompted for a new masterkey if you run this.
  changekey         | Change your masterkey, provided you remember the current one.

Flags:
  -help             | Displays this menu and exits.
  -verbose          | Prints extra info for debugging.
  -version          | Displays current version and exits.
  -parent           | Name this data should be under.
  -app              | App or website this data is for.
  -username         | Email or username.
  -password         | Password to use.
"""

  VERSION = "0.0.1"  # Idk how to version things I can't lie-

  def get(self) -> list[tuple[str, str | bool]]:
    final: list[tuple[str, str | bool]] = []
    flags = [a[1:] for a in argv if a[0] == '-']
    params = [a for a in argv if a[0] != '-']

    for flag in flags:
      match flag:
        case "help" | 'h':
          print(self.HELP_MSG)
          exit(0)

        case "version" | 'v':
          print(f"v{self.VERSION}")

        case "verbose" | 'vb': ...

    return final
