#include "pathpushbutton.hpp"

#include "tools/logger.hpp"

#include "hmi/mainwindow/pathpushbutton/filedialog.hpp"


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
PathPushButton::PathPushButton(QString const& p_objectName)
{
    s_objectName = p_objectName;
    LOGGER::DDEBUG(s_objectName, Q_FUNC_INFO, "creation...");
    setText("...");
    setFixedSize(50,30);
    QObject::connect(this, SIGNAL(released()), this, SLOT(openFileDialog()));
    LOGGER::DDEBUG(s_objectName, Q_FUNC_INFO, "created");
}




/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString SelectFilePathPushButton::s_classname="SelectFilePathPushButton";
const QString SelectFilePathPushButton::s_movie_fileFilter="*.mkv *.mp4";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
SelectFilePathPushButton::SelectFilePathPushButton(FileType const& p_fileType) : PathPushButton(SelectFilePathPushButton::s_classname)
{
    fileFilter="";
    if(p_fileType==MOVIES) { fileFilter = s_movie_fileFilter; }
}


/* -------------------------------------------------------
 * Private slots
 * ------------------------------------------------------- */
void SelectFilePathPushButton::openFileDialog()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    QString l_resultat = FileDialog::searchForFile("", fileFilter);
    if ( l_resultat.isEmpty() )
    { emit s_noChangePath(); }
    emit s_changePath(l_resultat);
}



/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString SelectDirPathPushButton::s_classname="SelectDirPathPushButton";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
SelectDirPathPushButton::SelectDirPathPushButton() : PathPushButton(SelectDirPathPushButton::s_classname)
{
}


/* -------------------------------------------------------
 * Private slots
 * ------------------------------------------------------- */
void SelectDirPathPushButton::openFileDialog()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    QString l_resultat = FileDialog::searchForDir();
    if ( l_resultat.isEmpty() )
    { emit s_noChangePath(); }
    emit s_changePath(l_resultat);
}
