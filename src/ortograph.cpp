#include "ortograph.h"
#include "ui_ortograph.h"
#include <QFileSystemModel>
#include <QDir>
#include <fstream>




ortograph::ortograph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ortograph),
    file_system_model(new QFileSystemModel(this))
{
    ui->setupUi(this);

    QDir  dir("../data");
    file_system_model->setRootPath(dir.path());
    file_system_model->setNameFilters(QStringList() << "*.txt");
    file_system_model->setNameFilterDisables(false);
    ui->tv_exam->setModel(file_system_model);
    ui->tv_exam->setRootIndex(file_system_model->index(dir.path()));
    ui->tv_exam->setColumnWidth(0, 500);
    ui->tv_exam->setColumnHidden(1, true);
    ui->tv_exam->setColumnHidden(2, true);
    ui->tv_exam->setHeaderHidden(true);

    ui->tv_exam->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->lbl_status->setText("");

    for(unsigned i=0; i<get_options_ui_count(); ++i)
    {
        QOption*  option = get_option_by_index(i);
        connect(option, SIGNAL(signal_clicked(QOption*)), this, SLOT(slot_option_clicked(QOption*)));
    }

    ui->stackedWidget->setCurrentIndex(0);
}

ortograph::~ortograph()
{
    delete ui;
}


void ortograph::on_pb_start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    start_game();
}


void  ortograph::start_game(void)
{
    ui->lbl_status->setText("");
    status = ort::msg::sub_status(  mtk::dtNowLocal(),
                                    ui->sb_repetitions->value(),
                                    ui->sb_penalizations->value(),
                                    ui->sb_options->value(),
                                    0,
                                    ui->cb_tildes->isChecked(),
                                    ui->cb_english->isChecked(),
                                    ui->sb_repetitions->value());
    if(load_questions())
        ask_random_question();
}


void generate__substring__questions(mtk::list<std::string>  paragrah_list, mtk::list<ort::msg::sub_question>&  list_questions, const std::string&  c, const std::string& wrong)
{
    // for each paragraph, look for b and v and propose a question
    for(auto it=paragrah_list.begin(); it!=paragrah_list.end(); ++it)
    {
        std::string   paragraph = *it;
        std::string::size_type init_pos=0;
        std::string::size_type pos = paragraph.find(c, init_pos);
        std::string  space = (c[0] == ' '  ? "  " : "");
        while(pos!=std::string::npos)
        {
            std::string  question = MTK_SS(paragraph.substr(0, pos)  <<  space << "<font color=red>_</font color>" << paragraph.substr(pos+c.size()));
            //std::cout    <<  question  << std::endl;
            mtk::list<std::string>  answers;
            answers.push_back(MTK_SS(paragraph.substr(0, pos)  <<  "<font color=red>" << c << "</font color>" << paragraph.substr(pos+c.size())));
            mtk::list<std::string>  wrongs;
            wrongs.push_back(MTK_SS(paragraph.substr(0, pos)  <<  "<font color=red>" << wrong << "</font color>" << paragraph.substr(pos+c.size())));
            list_questions.push_back(ort::msg::sub_question(question, answers, wrongs));
            init_pos = pos+1;
            pos = paragraph.find(c, init_pos);
        }
    }
}

void generate__substring__reversible_questions(mtk::list<std::string>  paragrah_list, mtk::list<ort::msg::sub_question>&  list_questions, const std::string&  first, const std::string& second)
{
    generate__substring__questions(paragrah_list, list_questions, first, second);
    generate__substring__questions(paragrah_list, list_questions, second, first);
}


void generate__substring__reversible_questions_list(mtk::list<std::string>  paragrah_list, mtk::list<ort::msg::sub_question>&  list_questions, mtk::list<std::string> list2propose)
{
    while(list2propose.size())
    {
        std::string first = list2propose.front();
        list2propose.pop_front();

        for(auto item : list2propose)
            generate__substring__reversible_questions(paragrah_list, list_questions, first, item);
    }
}


void  load_from_file(const std::string& file_name, mtk::list<ort::msg::sub_question>&        list_questions, const ort::msg::sub_status& status)
{
    mtk::list<std::string>  paragrah_list;

    std::ifstream file(file_name.c_str());
    if (file.is_open())
    {
        while (file.good() )
        {
            std::string paragrah;
            getline (file, paragrah);
            paragrah_list.push_back(paragrah);
        }
        file.close();
    }

    if(status.english)
    {
        //  prepositions
        mtk::list<std::string>  list_prepositions;

        list_prepositions.clear();
        list_prepositions.push_back(" on ");
        list_prepositions.push_back(" in ");
        list_prepositions.push_back(" at ");
        list_prepositions.push_back(" since ");
        list_prepositions.push_back(" for ");
        list_prepositions.push_back(" ago ");
        list_prepositions.push_back(" before ");
        list_prepositions.push_back(" to ");
        list_prepositions.push_back(" till ");
        list_prepositions.push_back(" untill ");
        list_prepositions.push_back(" by ");
        generate__substring__reversible_questions_list(paragrah_list, list_questions, list_prepositions);

        list_prepositions.clear();
        list_prepositions.push_back(" in ");
        list_prepositions.push_back(" at ");
        list_prepositions.push_back(" on ");
        list_prepositions.push_back(" by ");
        list_prepositions.push_back(" nex to ");
        list_prepositions.push_back(" beside ");
        list_prepositions.push_back(" under ");
        list_prepositions.push_back(" below ");
        list_prepositions.push_back(" over ");
        list_prepositions.push_back(" above ");
        list_prepositions.push_back(" across ");
        list_prepositions.push_back(" throgh ");
        list_prepositions.push_back(" to ");
        list_prepositions.push_back(" into ");
        list_prepositions.push_back(" towards ");
        list_prepositions.push_back(" onto ");
        list_prepositions.push_back(" from ");
        generate__substring__reversible_questions_list(paragrah_list, list_questions, list_prepositions);

        list_prepositions.clear();
        list_prepositions.push_back(" from ");
        list_prepositions.push_back(" of ");
        list_prepositions.push_back(" by ");
        list_prepositions.push_back(" on ");
        list_prepositions.push_back(" in ");
        list_prepositions.push_back(" off ");
        list_prepositions.push_back(" out of ");
        list_prepositions.push_back(" by ");
        list_prepositions.push_back(" at ");
        list_prepositions.push_back(" about ");
        generate__substring__reversible_questions_list(paragrah_list, list_questions, list_prepositions);
    }
    else
    {
        generate__substring__reversible_questions(paragrah_list, list_questions, "b", "v");
        generate__substring__reversible_questions(paragrah_list, list_questions, "B", "V");
            generate__substring__reversible_questions(paragrah_list, list_questions, "b", "v");
            generate__substring__reversible_questions(paragrah_list, list_questions, "B", "V");
            generate__substring__reversible_questions(paragrah_list, list_questions, "b", "v");
            generate__substring__reversible_questions(paragrah_list, list_questions, "B", "V");

        generate__substring__reversible_questions(paragrah_list, list_questions, "ya", "lla");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ye", "lle");
        generate__substring__reversible_questions(paragrah_list, list_questions, "yi", "lli");
        generate__substring__reversible_questions(paragrah_list, list_questions, "yo", "llo");
        generate__substring__reversible_questions(paragrah_list, list_questions, "yu", "llu");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Ya", "Lla");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Ye", "Lle");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Yi", "Lli");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Yo", "Llo");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Yu", "Llu");

        generate__substring__reversible_questions(paragrah_list, list_questions, "ge", "je");
        generate__substring__reversible_questions(paragrah_list, list_questions, "gi", "ji");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Ge", "Je");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Gi", "Ji");
            generate__substring__reversible_questions(paragrah_list, list_questions, "ge", "je");
            generate__substring__reversible_questions(paragrah_list, list_questions, "gi", "ji");
            generate__substring__reversible_questions(paragrah_list, list_questions, "Ge", "Je");
            generate__substring__reversible_questions(paragrah_list, list_questions, "Gi", "Ji");

        generate__substring__reversible_questions(paragrah_list, list_questions, "ce", "ze");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ci", "zi");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Ce", "Ze");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Ci", "Zi");
            generate__substring__reversible_questions(paragrah_list, list_questions, "ce", "ze");
            generate__substring__reversible_questions(paragrah_list, list_questions, "ci", "zi");
            generate__substring__reversible_questions(paragrah_list, list_questions, "Ce", "Ze");
            generate__substring__reversible_questions(paragrah_list, list_questions, "Ci", "Zi");

        generate__substring__questions(paragrah_list, list_questions, "mp", "np");
        generate__substring__questions(paragrah_list, list_questions, "mb", "nb");
        generate__substring__questions(paragrah_list, list_questions, "nv", "mv");
            generate__substring__questions(paragrah_list, list_questions, "mp", "np");
            generate__substring__questions(paragrah_list, list_questions, "mb", "nb");
            generate__substring__questions(paragrah_list, list_questions, "nv", "mv");

        if(status.tildes)
        {
            generate__substring__reversible_questions(paragrah_list, list_questions, "á", "a");
            generate__substring__reversible_questions(paragrah_list, list_questions, "é", "e");
            generate__substring__reversible_questions(paragrah_list, list_questions, "í", "i");
            generate__substring__reversible_questions(paragrah_list, list_questions, "ó", "o");
            generate__substring__reversible_questions(paragrah_list, list_questions, "ú", "u");
        }

        generate__substring__questions(paragrah_list, list_questions, "x", "s");
        generate__substring__questions(paragrah_list, list_questions, "X", "S");
        generate__substring__questions(paragrah_list, list_questions, "sa", "xa");
        generate__substring__questions(paragrah_list, list_questions, "se", "xe");
        generate__substring__questions(paragrah_list, list_questions, "si", "xi");
        generate__substring__questions(paragrah_list, list_questions, "so", "xo");
        generate__substring__questions(paragrah_list, list_questions, "su", "xu");
        generate__substring__questions(paragrah_list, list_questions, "Sa", "Xa");
        generate__substring__questions(paragrah_list, list_questions, "Se", "Xe");
        generate__substring__questions(paragrah_list, list_questions, "Si", "Xi");
        generate__substring__questions(paragrah_list, list_questions, "So", "Xo");
        generate__substring__questions(paragrah_list, list_questions, "Su", "Xu");

        generate__substring__questions(paragrah_list, list_questions, "h", "_");
        generate__substring__questions(paragrah_list, list_questions, " a", " ha");
        generate__substring__questions(paragrah_list, list_questions, " e", " he");
        generate__substring__questions(paragrah_list, list_questions, " i", " hi");
        generate__substring__questions(paragrah_list, list_questions, " o", " ho");
        generate__substring__reversible_questions(paragrah_list, list_questions, "aa", "aha");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ae", "ahe");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ai", "ahi");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ao", "aho");
        generate__substring__reversible_questions(paragrah_list, list_questions, "au", "ahu");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ea", "eha");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ee", "ehe");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ei", "ehi");
        generate__substring__reversible_questions(paragrah_list, list_questions, "eo", "eho");
        generate__substring__reversible_questions(paragrah_list, list_questions, "eu", "ehu");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ia", "iha");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ie", "ihe");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ii", "ihi");
        generate__substring__reversible_questions(paragrah_list, list_questions, "io", "iho");
        generate__substring__reversible_questions(paragrah_list, list_questions, "iu", "ihu");
        generate__substring__reversible_questions(paragrah_list, list_questions, "oa", "oha");
        generate__substring__reversible_questions(paragrah_list, list_questions, "oe", "ohe");
        generate__substring__reversible_questions(paragrah_list, list_questions, "oi", "ohi");
        generate__substring__reversible_questions(paragrah_list, list_questions, "oo", "oho");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ou", "ohu");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ua", "uha");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ue", "uhe");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ui", "uhi");
        generate__substring__reversible_questions(paragrah_list, list_questions, "uo", "uho");
        generate__substring__reversible_questions(paragrah_list, list_questions, "uu", "uhu");

        generate__substring__reversible_questions(paragrah_list, list_questions, "cómo", "como");
        generate__substring__questions(paragrah_list, list_questions, "porque", "por que");
        generate__substring__questions(paragrah_list, list_questions, "porque", "porqué");
        generate__substring__questions(paragrah_list, list_questions, "porque", "por qué");
        generate__substring__questions(paragrah_list, list_questions, "por que", "porque");
        generate__substring__questions(paragrah_list, list_questions, "por que", "porqué");
        generate__substring__questions(paragrah_list, list_questions, "por que", "por qué");
        generate__substring__questions(paragrah_list, list_questions, "por qué", "porque");
        generate__substring__questions(paragrah_list, list_questions, "por qué", "porqué");
        generate__substring__questions(paragrah_list, list_questions, "por qué", "por que");
        generate__substring__questions(paragrah_list, list_questions, "porqué", "por que");
        generate__substring__questions(paragrah_list, list_questions, "porqué", "porque");
        generate__substring__questions(paragrah_list, list_questions, "porqué", "por qué");

        generate__substring__reversible_questions(paragrah_list, list_questions, "ado ", "ao ");
        generate__substring__reversible_questions(paragrah_list, list_questions, "edo ", "eo ");
        generate__substring__reversible_questions(paragrah_list, list_questions, "ido ", "io ");
        generate__substring__reversible_questions(paragrah_list, list_questions, "udo ", "uo ");

        generate__substring__reversible_questions(paragrah_list, list_questions, "él ", "el ");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Él ", "El ");

        generate__substring__reversible_questions(paragrah_list, list_questions, "sí ", "si ");
        generate__substring__reversible_questions(paragrah_list, list_questions, "Sí ", "Si ");
    }
}


QOption*  ortograph::get_option_by_index(int index)
{
#define __GET_OPTION_BY_INDEX__(__INDEX__)  \
    if(index==__INDEX__)        return  ui->option##__INDEX__;

    __GET_OPTION_BY_INDEX__(0);
    __GET_OPTION_BY_INDEX__(1);
    __GET_OPTION_BY_INDEX__(2);
    __GET_OPTION_BY_INDEX__(3);
    __GET_OPTION_BY_INDEX__(4);
    __GET_OPTION_BY_INDEX__(5);
    __GET_OPTION_BY_INDEX__(6);
    __GET_OPTION_BY_INDEX__(7);
    __GET_OPTION_BY_INDEX__(8);
    __GET_OPTION_BY_INDEX__(9);

    return 0;
}

bool  ortograph::load_questions(void)
{
    list_questions.clear();
    vector_questions.clear();


    QModelIndexList selections = ui->tv_exam->selectionModel()->selectedRows();

    for(int i=0; i<selections.count(); ++i)
    {
        QModelIndex  index = selections.at(i);
        if(file_system_model->isDir(index) == false)
            load_from_file(file_system_model->filePath(index).toUtf8().data(), list_questions, status.Get());
    }
    if(list_questions.size() == 0)
    {
        ui->lbl_status->setText("empty questions");
        ui->stackedWidget->setCurrentIndex(0);
    }
    for(auto it=list_questions.begin(); it!=list_questions.end(); ++it)
        vector_questions.push_back(*it);

    return  (vector_questions.size() >0 ? true : false);
}


void  ortograph::clear_ui_options(void)
{
    for(unsigned i=0; i<get_options_ui_count(); ++i)
    {
        QOption*  option = get_option_by_index(i);
        option->setText("");
        option->setVisible(false);
        option->setEnabled(false);
        option->setStyleSheet("");
    }
}

void ortograph::ask_random_question(void)
{
    ort::msg::sub_question  random_question =  vector_questions[mtk::rand()%vector_questions.size()];


    clear_ui_options();
    configure_ui_options(random_question);
    update_counter();
}

void  ortograph::update_counter(void)
{
    ui->lbl_counter->setText(MTK_SS(status.Get().pendings <<":" << status.Get().repetitions).c_str());
}


std::string   pick_random_right_answer(const mtk::list<std::string>& answer_list)
{
    mtk::vector<std::string> answer_vector;
    for(auto it=answer_list.begin(); it!=answer_list.end(); ++it)
        answer_vector.push_back(*it);

    return answer_vector[mtk::rand()%answer_vector.size()];
}

mtk::tuple<std::string, std::string>   pick_2_random_answers(const mtk::list<std::string>& answer_list)
{
    mtk::vector<std::string> answer_vector;
    for(auto it=answer_list.begin(); it!=answer_list.end(); ++it)
        answer_vector.push_back(*it);

    unsigned first  = mtk::rand()%answer_vector.size();
    unsigned second=0;
    if(answer_vector.size() != 1)
    {
        while(second == first)
            second = mtk::rand()%answer_vector.size();
    }
    return mtk::make_tuple (
                answer_vector[first],
                answer_vector[second]
                );
}

void  ortograph::configure_ui_options(const  ort::msg::sub_question&  question_info)
{
    mtk::vector<std::string>  all_options_vector;
    for(auto it=question_info.wrong_options.begin(); it!=question_info.wrong_options.end(); ++it)
        all_options_vector.push_back(*it);

    std::string  question = question_info.question;
    std::string  right_answer;
    if(question != ""  &&  question != "~")
    {
        right_answer = pick_random_right_answer(question_info.answers);
    }
    else
    {
        mtk::tuple<std::string, std::string>  _2answers = pick_2_random_answers(question_info.answers);
        question = _2answers._0;
        right_answer = _2answers._1;
    }

    ui->lbl_question->setText(QString::fromUtf8(question.c_str()));

    //  riffle answers
    for(unsigned i=0; i<all_options_vector.size()*10; i++)
    {
        int index1 = mtk::rand()%all_options_vector.size();
        int index2 = mtk::rand()%all_options_vector.size();

        std::swap(all_options_vector[index1], all_options_vector[index2]);
    }

    unsigned number_questions = (unsigned(status.Get().options_per_question)<(question_info.wrong_options.size()+1)
                                 ?
                                     unsigned(status.Get().options_per_question)
                                   : question_info.wrong_options.size()+1);
    unsigned pos_right_question = mtk::rand() % number_questions;
    all_options_vector.push_back(right_answer);

    std::swap(all_options_vector[pos_right_question], all_options_vector[all_options_vector.size()-1]);

    for(unsigned i=0; i<number_questions; ++i)
    {
        QOption* option = get_option_by_index(i);
        option->setText(QString::fromUtf8(all_options_vector[i].c_str()));
        option->setEnabled(true);
        option->setVisible(true);
        if(i==pos_right_question)
            option->correct_option = true;
        else
            option->correct_option = false;
    }
}


void ortograph::slot_option_clicked(QOption* option)
{
    if(option->correct_option == false)
    {
        option->setStyleSheet("background-color: rgb(255, 200, 200);");
        status.Get().pendings += status.Get().penalizations;
        status.Get().failed += 1;
        update_counter();
    }
    else
    {
        status.Get().pendings -= 1;
        update_counter();
        if(status.Get().pendings == 0)
            go_congratulations();
        else
            ask_random_question();
    }
}

void  ortograph::go_congratulations(void)
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->pte_report->setPlainText(QString::fromUtf8(MTK_SS(
                                            "Time:  " << mtk::dtNowLocal() - status.Get().started << std::endl  << std::endl
                                     << YAML::string_from_yaml(status)
                                                       ).c_str()));
}

void ortograph::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
