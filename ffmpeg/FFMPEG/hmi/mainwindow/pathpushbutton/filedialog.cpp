#include "filedialog.hpp"
#include "tools/logger.hpp"

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString FileDialog::s_classname="FileDialog";


/* -------------------------------------------------------
 * Static Function initialisation
 * ------------------------------------------------------- */
const QString FileDialog::searchForFile(QString const& p_path, QString const& p_filter)
{
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, "called");
    QFileDialog l_filedialog;
    if( !p_filter.isEmpty() ) { l_filedialog.setNameFilter(p_filter); }
    if( !p_path.isEmpty() )   { l_filedialog.setDirectory(p_path); }
    l_filedialog.setFileMode(QFileDialog::ExistingFile);
    if( !l_filedialog.exec() )
    {
        if( l_filedialog.selectedFiles().length() < 1 )
        {
            LOGGER::WARNING(s_classname, Q_FUNC_INFO, "no file selected");
            return "";
        }
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "execution error");
        return "";
    }
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "File '" + l_filedialog.selectedFiles()[0] + "' is selected");
    return l_filedialog.selectedFiles()[0];
}

// -------------------------------------------------------
const QString FileDialog::searchForDir(QString const& p_path)
{
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, "called");
    QFileDialog l_filedialog;
    if( !p_path.isEmpty() )   { l_filedialog.setDirectory(p_path); }
    l_filedialog.setFileMode(QFileDialog::Directory);
    if( !l_filedialog.exec() )
    {
        if( l_filedialog.selectedFiles().length() < 1 )
        {
            LOGGER::WARNING(s_classname, Q_FUNC_INFO, "no directory selected");
            return "";
        }
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "execution error");
        return "";
    }
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "Directory '" + l_filedialog.selectedFiles()[0] + "' is selected");
    return l_filedialog.selectedFiles()[0];

}
