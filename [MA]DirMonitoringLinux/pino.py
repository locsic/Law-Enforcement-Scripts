import pyinotify


class MyEventHandler(pyinotify.ProcessEvent):
  def process_IN_ACCESS(self, event):
    print "ACCESS event:", event.pathname

  def process_IN_ATTRIB(self, event):
    print "ATTRIB event:", event.pathname

  def process_IN_CLOSE_NOWRITE(self, event):
    print "CLOSE_NOWRITE event:", event.pathname

  def process_IN_CLOSE_WRITE(self, event):
    print "CLOSE_WRITE event:", event.pathname

  def process_IN_CREATE(self, event):
    print "CREATE event:", event.pathname

  def process_IN_DELETE(self, event):
    print "DELETE event:", event.pathname

  def process_IN_MODIFY(self, event):
    print "MODIFY event:", event.pathname

  def process_IN_OPEN(self, event):
    print "OPEN event:", event.pathname

def main():
  # watch manager
  wm = pyinotify.WatchManager()
  wm.add_watch('/var/log', pyinotify.ALL_EVENTS, rec=True)
  # event handler
  eh = MyEventHandler()

  # notifier
  notifier = pyinotify.Notifier(wm, eh)
  notifier.loop()

if __name__ == '__main__':
  main()
