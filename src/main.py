from backend.args import Args


if __name__ == "__main__":
  (args:=Args()).get()
  if args.has("verbose") or args.has("vb"): print("Verbose enabled!")
