<?php
/**
 * Implements hook_views_data().
 */
function test_views_views_data() {
    $data = array();
    $data['test_views']['table']['group'] = t('Test views');
    $data['test_views']['table']['join']['node'] = array(
        'left_field' => 'nid', // ключевое поле из базовой таблицы, т.е из {node}
        'field' => 'nid',      // ключевое поле из подключаемой таблицы, т.е из {test_views}
    );

    // рассказываем views о текстовом поле version из таблицы versionfield
   /*$data['test_views']['version'] = array(
        'title'  => 'Написанное актуально для',
        'help'   => 'Версия скриптов используемых в заметке',
        'group'  => t('test_views'),                                         // группа, к которой будет принадлежать поле
        'field'  => array('handler' => 'views_handler_field'),         // указываем на возможность добавлять поле в блоке Поля
        'sort'   => array('handler' => 'views_handler_sort'),          // указываем на возможность сортировки по этому полю в блоке Критерии сортировки
        'filter' => array('handler' => 'views_handler_filter_string'), // указываем на возможность фильтровать по этому полю в блоке Фильтры
    ); */

    $data['test_views']['nid'] = array(
        'title' => t('Nid'),
        'help' => t('The node ID of the test_views.'), // The help that appears on the UI,
        // Information for displaying the nid
        'field' => array(
            'handler' => 'views_handler_field_node',
            'click sortable' => TRUE,
        ),
        // Information for accepting a nid as an argument
        'argument' => array(
            'handler' => 'views_handler_argument_node_nid',
            'name field' => 'title', // the field to display in the summary.
            'numeric' => TRUE,
            'validate type' => 'nid',
        ),
        // Information for accepting a nid as a filter
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        // Information for sorting on a nid.
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'relationship' => array(
            'label' => t('Node'),
            'base' => 'node',
            'base field' => 'nid',
        ),
    );
    $data['test_views']['uid'] = array(
        'title' => t('Uid'),
        'help' => t('The user IDs of the test_views.'), // The help that appears on the UI,
        // Information for displaying the nid
        'field' => array(
            'handler' => 'views_handler_field_user_link',
            'click sortable' => TRUE,
        ),
        // Information for accepting a nid as an argument
        'argument' => array(
            'handler' => 'views_handler_argument_user_uid',
            'name field' => 'title', // the field to display in the summary.
            'numeric' => TRUE,
        ),
        // Information for accepting a nid as a filter
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        // Information for sorting on a nid.
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'relationship' => array(
            'label' => t('User'),
            'base' => 'users',
            'base field' => 'uid',
        ),
    );



    return $data;
}
