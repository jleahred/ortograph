#ifndef ORTOGRAPH__H
#define ORTOGRAPH__H

#include <QWidget>


#include "db/msg_structs.h"
#include "support/list.hpp"
#include "support/vector.hpp"


class QFileSystemModel;
class QOption;


namespace Ui {
class ortograph;
}

class ortograph : public QWidget
{
    Q_OBJECT
    
public:
    explicit ortograph(QWidget *parent = 0);
    ~ortograph();
    
private slots:
    void on_pb_start_clicked();
    void slot_option_clicked(QOption* option);

    void on_pushButton_clicked();

private:
    Ui::ortograph *ui;

    mtk::nullable<ort::msg::sub_status>      status;
    QFileSystemModel*                       file_system_model;



    mtk::list<ort::msg::sub_question>        list_questions;
    mtk::vector<ort::msg::sub_question>     vector_questions;

    void  start_game(void);
    bool  load_questions(void);
    void  ask_random_question(void);
    void  clear_ui_options(void);
    void  configure_ui_options(const  ort::msg::sub_question& question);
    void  update_counter(void);
    void  go_congratulations(void);


    unsigned  get_options_ui_count(void) const  {  return 10;  }
    QOption*  get_option_by_index(int index);

};

#endif // ORTOGRAPH__H
