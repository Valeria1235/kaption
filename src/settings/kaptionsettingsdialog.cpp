#include "kaptionsettingsdialog.h"

#include <KLocale>
#include <KConfigSkeleton>
#include <QDebug>

#include "settings.h"

#include "ftpuploadsettingspage.h"
#include "generalsettingspage.h"

KaptionSettingsDialog::KaptionSettingsDialog(QWidget *parent,
                                             const char *name,
                                             KConfigSkeleton *config)
    : KConfigDialog(parent, name, config)
{
    setButtons(Ok | Apply | Cancel);

    addPage(new GeneralSettingsPage(this),
            i18n("General"),
            "system-run",
            i18n("Configure general settings"));

    addPage(new FtpUploadSettingsPage(this),
            i18n("Upload"),
            "upload",
            i18n("Configure upload"));
}

KaptionSettingsDialog::~KaptionSettingsDialog()
{

}

void KaptionSettingsDialog::show(const QString &page)
{
    if (!page.isEmpty()) {
        if (m_pagesMap.contains(page)) {
            setCurrentPage(m_pagesMap.value(page));
        }
    }

    KConfigDialog::show();
    raise();
    activateWindow();
}

KPageWidgetItem *KaptionSettingsDialog::addPage(QWidget *page,
                                                const QString &itemName,
                                                const QString &pixmapName,
                                                const QString &header,
                                                bool manage)
{
    KPageWidgetItem *item = KConfigDialog::addPage(page, itemName,
                                                   pixmapName, header, manage);
    m_pagesMap.insert(page->metaObject()->className(), item);
    return item;
}

KPageWidgetItem *KaptionSettingsDialog::addPage(QWidget *page,
                                                KConfigSkeleton *config,
                                                const QString &itemName,
                                                const QString &pixmapName,
                                                const QString &header)
{
    KPageWidgetItem *item = KConfigDialog::addPage(page, config, itemName,
                                                   pixmapName, header);
    m_pagesMap.insert(page->metaObject()->className(), item);
    return item;
}
